#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <map>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Grafo {
private:
    // Set de Vértices
    set<string> vertices;
    // Mapa para asociar índices a vértices
    map<string, int> indice;
    // Cantidad de vértices
    int V;
    // Lista de adyacencia
    vector<list<string>> adj;

public:
    // Constructor
    Grafo(const set<string>& vertices) : vertices(vertices), V(vertices.size()), adj(vertices.size()) {
        int index = 0;
        for (const auto& vertex : vertices) {
            indice[vertex] = index++;
        }
    }

    // Método para agregar una arista
    void agregarArista(const string& v, const string& w) {
        if (indice.find(v) != indice.end() && indice.find(w) != indice.end()) {
            adj[indice[v]].push_back(w);
            adj[indice[w]].push_back(v);
        } else {
            cerr << "Error: Uno o ambos vértices no existen.\n";
        }
    }

    // Método para mostrar el grafo en formato DOT
    void generarDOT(const std::string& filename) const {
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



    vector<string> BFS(const string& s) {
        vector<string> padre(V, ""); // padre[v] = vértice desde el que se llega a v
        vector<bool> explorado(V, false); // explorado[v] = false 
        //Se crea la Capa L[0]
        list<string> L;
        L.push_back(s);
        explorado[indice[s]] = true;
        while (!L.empty()) {
            list<string> L1;  // Capa L[i+1]
            for (const auto& u : L) { // Recorremos los vértices de la capa L[i]
                for (const auto& v : adj[indice[u]]) { // Recorremos los vecinos de u
                    if (!explorado[indice[v]]) {
                        explorado[indice[v]] = true; // v es descubierto
                        padre[indice[v]] = u; // v es descubierto por u
                        L1.push_back(v); // Agregamos v a la capa L[i+1]
                    }
                }
            }
            L = L1; // Pasamos a la siguiente capa 
        }
        return padre;
    }

    // Método para construir un árbol BFS a partir de padres
    Grafo construirArbolBFSAPartirPadre(const vector<string>& padre) {
        Grafo arbol(vertices); // Crear un nuevo grafo para el árbol BFS
        for (int i = 0; i < V; ++i) {
            if (padre[i] != "" && padre[i] != getVertexByIndex(i)) { // Ignorar la raíz
                arbol.agregarArista(padre[i], getVertexByIndex(i)); // Agregar la arista usando los nombres de los vértices
            }
            else if (padre[i] == getVertexByIndex(i)) {
                arbol.agregarArista(padre[i], getVertexByIndex(i));
            }
        }
        return arbol;
    }

    // Método auxiliar para obtener un vértice por índice
    string getVertexByIndex(int index) const {
        for (const auto& pair : indice) {
            if (pair.second == index) {
                return pair.first;
            }
        }
        return ""; // En caso de que no se encuentre
    }

     // Función para medir el tiempo de BFS
    long long medirTiempoBFS(const string& s) {
        auto start = high_resolution_clock::now();
        BFS(s);
        auto stop = high_resolution_clock::now();
        return duration_cast<microseconds>(stop - start).count(); // Retorna el tiempo en microsegundos
    }


    vector<string> DFS(const string& s) {
        vector<string> padre(V, ""); // padre[v] = vértice desde el que se llega a v
        vector<bool> descubierto(V, false); // explorado[v] = false
        //usamos pila
        list<string> pila;
        pila.push_back(s);
        descubierto[indice[s]] = true;
        while (!pila.empty()) {
            string u = pila.back();
            pila.pop_back();
            for (const auto& v : adj[indice[u]]) {
                if (!descubierto[indice[v]]) {
                    descubierto[indice[v]] = true; // v es descubierto
                    padre[indice[v]] = u; // v es descubierto por u
                    pila.push_back(v); // Agregamos v a la pila
                }
            }
        }
        return padre;
    }


        
};