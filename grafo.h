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

    // Lista de adyacencia del grafo con String NO DIRIGIDO
    vector<list<string>> adj;

public:
    // Constructor
    Grafo(const set<string>& vertices);

    int getV() const;

    // Método para agregar una arista
    void agregarArista(const string& v, const string& w);

    // Método para mostrar el grafo en formato DOT
    void generarDOT(const std::string& filename) const;

 
public:
    std::vector<std::string> BFS(const string& s);


    // Método para construir un árbol BFS a partir de padres
    Grafo construirArbolConPadres(const vector<string>& padre);

    // Método auxiliar para obtener un vértice por índice
    string getVertexByIndex(int index) const;

     // Función para medir el tiempo de BFS
    long long medirTiempoBFS(const string& s);

    vector<string> DFS(const string& s);

    vector<string> DFSRecursivo(const string& s, vector<bool>& explorado, vector<string>& padre);


        
};