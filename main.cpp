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



    grafo.generarDOT("salidas/grafo2.dot");

    vector<string> padre = grafo.BFS("A");
       // Medir tiempo de BFS
    long long tiempo = grafo.medirTiempoBFS("A");
    cout << "Tiempo de ejecución de BFS: " << tiempo << " microsegundos" << endl;
    Grafo arbol = grafo.construirArbolConPadres(padre);
    
    
    arbol.generarDOT("salidas/arbol2.dot");

    //DFS
    padre = grafo.DFS("A");
    arbol = grafo.construirArbolConPadres(padre);
    arbol.generarDOT("salidas/arbol2DFS.dot");







 srand(static_cast<unsigned int>(time(0))); // Semilla para aleatoriedad

    // Crear un grafo grande
    vertices.clear();
    const int numVertices = 10000; // 10,000 vértices
    const int numAristas = 50000; // 50,000 aristas

    // Generar vértices
    for (int i = 0; i < numVertices; ++i) {
        //vertices.insert(to_string(i));
    }

   // Grafo g(vertices);

    // Agregar aristas aleatorias
    for (int i = 0; i < numAristas; ++i) {
        int v1 = rand() % numVertices;
        int v2 = rand() % numVertices;
        if (v1 != v2) { // Evitar bucles
      //      g.agregarArista("V" + to_string(v1), "V" + to_string(v2));
        }
    }

    // Medir tiempo de BFS una sola vez
    // tiempo = g.medirTiempoBFS("V0");
  //  cout << "Tiempo de ejecución de BFS: " << tiempo << " microsegundos" << endl;
    

    vertices.clear();
    vertices = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13"};
    Grafo g2(vertices);
    g2.agregarArista("1", "2");
    g2.agregarArista("1", "3");
    g2.agregarArista("2", "3"),
    g2.agregarArista("2", "4");
    g2.agregarArista("2", "5");
    g2.agregarArista("3", "7");
    g2.agregarArista("3", "8");
    g2.agregarArista("3", "5");
    g2.agregarArista("4", "5");
    g2.agregarArista("5", "6");
    g2.agregarArista("7", "8");
    g2.agregarArista("9", "10");
    g2.agregarArista("11", "12");
    g2.agregarArista("12", "13");

    g2.generarDOT("salidas/grafofig3-2.dot");



    vector<bool> explored(13, false);
    padre.clear();
    
    padre = vector<string>(13, "");
    padre = g2.DFSRecursivo("1", explored, padre);
    
    Grafo arbolDFSfig3 = g2.construirArbolConPadres(padre);
    arbolDFSfig3.generarDOT("salidas/arbolDFSfig3-2.dot");
 

    padre.clear();
    vector<string> a = g2.BFS("1");
    Grafo arbolBFSfig3 = g2.construirArbolConPadres(a);
    arbolBFSfig3.generarDOT("salidas/arbolBFSfig3-2.dot");





    return 0;
}
