#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <iostream>
#include "grafo.h"


int main() {
    set<string> vertices = {"A", "B", "C", "D", "E"};
    
    Grafo grafo(vertices);


    grafo.agregarArista("A", "B");
    grafo.agregarArista("A", "C");
    grafo.agregarArista("B", "D");
    grafo.agregarArista("C", "D");
    grafo.agregarArista("D", "E");
    grafo.agregarArista("E", "A");
    grafo.agregarArista("E", "B");
    grafo.agregarArista("E", "C");



    grafo.generarDOT("grafo2.dot");

    vector<string> padre = grafo.BFS("A");
       // Medir tiempo de BFS
    long long tiempo = grafo.medirTiempoBFS("A");
    cout << "Tiempo de ejecución de BFS: " << tiempo << " microsegundos" << endl;
    Grafo arbol = grafo.construirArbolBFSAPartirPadre(padre);
    
    
    arbol.generarDOT("arbol2.dot");

    //DFS
    padre = grafo.DFS("A");
    arbol = grafo.construirArbolBFSAPartirPadre(padre);
    arbol.generarDOT("arbol2DFS.dot");







 srand(static_cast<unsigned int>(time(0))); // Semilla para aleatoriedad

    // Crear un grafo grande
    vertices.clear();
    const int numVertices = 10000; // 10,000 vértices
    const int numAristas = 50000; // 50,000 aristas

    // Generar vértices
    for (int i = 0; i < numVertices; ++i) {
        vertices.insert("V" + to_string(i));
    }

    Grafo g(vertices);

    // Agregar aristas aleatorias
    for (int i = 0; i < numAristas; ++i) {
        int v1 = rand() % numVertices;
        int v2 = rand() % numVertices;
        if (v1 != v2) { // Evitar bucles
            g.agregarArista("V" + to_string(v1), "V" + to_string(v2));
        }
    }

    // Medir tiempo de BFS una sola vez
     tiempo = g.medirTiempoBFS("V0");
    cout << "Tiempo de ejecución de BFS: " << tiempo << " microsegundos" << endl;
     // Guardar tiempos en un archivo
        ofstream archivo("tiempos_bfs_grafo_grande.txt");
        for (int i = 0; i < 13; ++i) {
            archivo << "V" << i << " " << g.medirTiempoBFS("V" + to_string(i)) << endl;
        }
        archivo.close();

        // Crear archivo DOT
        ofstream dotFile("grafico_bfs.dot");
        dotFile << "digraph G {\n";
        dotFile << "    rankdir=LR;\n"; // Para que el gráfico sea de izquierda a derecha
        dotFile << "    node [shape=circle];\n";

        //Graficar Tiempo Lineal vertice en funcion de aristas
        for (int i = 0; i < 13; ++i) {
            dotFile << "    V" << i << " [label=\"V" << i << "\\n" << g.medirTiempoBFS("V" + to_string(i)) << " us\"];\n";
        }




        dotFile << "}\n";
        dotFile.close();

        // Generar imagen PNG usando Graphviz
        system("dot -Tpng grafico_bfs.dot -o grafico_bfs.png");
    






    return 0;
}
