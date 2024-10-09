#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
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
    int id;
    string nome;
    nodo(int id) : id(id) {}
    //Overload dell'operatore == per efficiente hash con unordered_map
    bool operator==(const nodo& oth) const {
        return id == oth.id;
    }
    //Funzione hash
    template<>
    struct hash<nodo> {
        size_t operator()(const nodo& n) const noexcept {
            return hash<int>()(n.id);
        }
    }
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
    void dfs(nodo att, set<nodo>& visitati);
};