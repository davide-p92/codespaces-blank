#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>


using namespace std;

enum class Tipo {
    SorgenteV = 0,
    Resistenza = 1,
    Condensatore = 2,
    Induttanza = 3,
    CortoCircuito = 4
};

class nodo {
public:
    int id;
    nodo(int id) : id(id) {}
    //Overload dell'operatore == per efficiente hash con unordered_map
    bool operator==(const nodo& oth) const {
        return id == oth.id;
    }
};

//Funzione hash
template<>
struct hash<nodo> {
    size_t operator()(const nodo& n) const noexcept {
        return hash<int>()(n.id);
    }
};

class bipolo {
public:
    int id;
    string nome;
    Tipo tipo;
    bipolo(int id, const string& nome, Tipo tipo, const nodo& n1, const nodo& n2, float voltaggio = 0.0, float corrente = 0.0)
        : id(id), nome(nome), tipo(tipo), nodo1(n1), nodo2(n2), voltaggio(voltaggio), corrente(corrente) {}
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
    int id;
    //void risolvi(bipolo bp0);
    unordered_map<nodo, vector<pair<bipolo, nodo>>> grafo;
    void aggiungiBipolo(nodo n1, bipolo b, nodo n2);
    void attraversaDaSx(nodo inizio);
    circuito(int id) : id(id) {}
private:
    void dfs(nodo att, set<nodo>& visitati);
};