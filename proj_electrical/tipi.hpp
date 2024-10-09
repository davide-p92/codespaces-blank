#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>


using namespace std;

enum class Tipo {
    SorgenteV,
    Resistenza,
    Condensatore,
    Induttanza,
    CortoCircuito
};

class nodo {
public:
    string nome;
};

class bipolo {
public:
    string nome;
    Tipo tipo;
    nodo nodo1;
    nodo nodo2;
    float voltaggio;
    float corrente;
    vector<bipolo> paralleli;
    map<nodo, vector<bipolo>> serie;
};

class circuito {
public:
    vector<bipolo> bipoli;
    //void risolvi(bipolo bp0);
    unordered_map<nodo, vector<pair<bipolo, nodo>>> grafo;
    void aggiungiBipolo(nodo n1, bipolo b, nodo n2);
    void attraversaDaSx(nodo inizio);
private:
    void dfs(nodo att, unordered_map<nodo, bool>& visitati);
};