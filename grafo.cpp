#include <fstream>
#include <list>
#include <vector>
#include <string>
#include "grafo.h"



//Constructor Grafo
Grafo::Grafo(const set<string>& vertices) : vertices(vertices), V(vertices.size()), adj(vertices.size()) {
    int index = 0;
    for (const auto& vertex : vertices) {
        indice[vertex] = index++;
    }
}

//Método para obtener la cantidad de vértices
int Grafo::getV() const {
    return V;
}

//Método para agregar una arista
void Grafo::agregarArista(const string& v, const string& w) {
    if (indice.find(v) != indice.end() && indice.find(w) != indice.end()) {
        adj[indice[v]].push_back(w);
        adj[indice[w]].push_back(v);
    } else {
        cerr << "Error: Uno o ambos vértices no existen.\n";
    }
}

//Método para mostrar el grafo en formato DOT 
void Grafo::generarDOT(const std::string& filename) const {
    std::ofstream file(filename);
    file << "graph G {\n";
    for (const auto& vertex : vertices) {
        int u = indice.at(vertex);
        for (const auto& v : adj[u]) {
            if (u < indice.at(v)) { // Evitar duplicados
                file << "    \"" << vertex << "\" -- \"" << v << "\";\n";
            }
        }
    }
    file << "}\n";
    file.close();

    // Generar la imagen automáticamente
    string command = "dot -Tpng " + filename + " -o " + filename + ".png";
    system(command.c_str());
}
 

vector<string> Grafo::BFS(const string& s) {
    vector<string> padre(V, ""); // padre[v] = vértice desde el que se llega a v
    vector<bool> descubierto(V, false); // explorado[v] = false 
    descubierto[indice[s]] = true;
    //Se crea la Capa L[0]
    vector<list<string>> L = vector<list<string>>(1);
    L[0].push_back(s);
    int i = 0;
    
    while (!L[i].empty()) {
        L.push_back(list<string>()); // Se crea la capa L[i+1]
        for (const auto& u : L[i]) { // Recorremos los vértices de la capa L[i]
            for (const auto& v : adj[indice[u]]) { // Recorremos los vecinos de u
                if (!descubierto[indice[v]]) {
                    descubierto[indice[v]] = true; // v es descubierto
                    padre[indice[v]] = u; // v es descubierto por u
                    L[i+1].push_back(v); // Agregamos v a la capa L[i+1]
                }
            }
        }
        i = i+1; // Pasamos a la siguiente capa 
    }
    return padre;
}

vector<string> Grafo::DFS(const string& s) {
    vector<string> padre(V, ""); // padre[v] = vértice desde el que se llega a v
    vector<bool> explorado(V, false); // explorado[v] = false
    //usamos pila
    list<string> pila;
    pila.push_back(s);
    explorado[indice[s]] = true;
    while (!pila.empty()) {
        string u = pila.back();
        pila.pop_back();
        for (const auto& v : adj[indice[u]]) {
            if (!explorado[indice[v]]) {
                explorado[indice[v]] = true; // v es descubierto
                padre[indice[v]] = u; // v es descubierto por u
                pila.push_back(v); // Agregamos v a la pila
            }
        }
    }
    return padre;
}


vector<string> Grafo::DFSRecursivo(const string& s, vector<bool>& explorado, vector<string>& padre) {
    explorado[indice[s]] = true;
    for(const auto& v : adj[indice[s]]) {
        if (!explorado[indice[v]]) {
            padre[indice[v]] = s;
            padre = Grafo::DFSRecursivo(v, explorado, padre);
        }
    }
    return padre;
}


// Método para construir un grafo a partir de padres
Grafo Grafo::construirArbolConPadres(const vector<string>& padre) {
    Grafo arbol(vertices);

    for (int i = 0; i < V; ++i) {
        if (padre[i] != "") { // Ignorar la raíz
            arbol.agregarArista(padre[i], getVertexByIndex(i)); 
        }
    }

    return arbol;
}


// Función para medir el tiempo de BFS
long long Grafo::medirTiempoBFS(const string& s) {
    auto start = high_resolution_clock::now();
    BFS(s);
    auto stop = high_resolution_clock::now();
    return duration_cast<microseconds>(stop - start).count(); // Retorna el tiempo en microsegundos
}

// Método auxiliar para obtener un vértice por índice
string Grafo::getVertexByIndex(int index) const {
    for (const auto& pair : indice) {
        if (pair.second == index) {
            return pair.first;
        }
    }
    return ""; // En caso de que no se encuentre
}




// #include <iostream>


// #ifdef _GLIBCXX_DEBUG

// #include <debug/vector>


// #endif
