#include <iostream>
#include <string>
#include <vector>
#include <map>
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
};

class circuito {
    vector<bipolo> bipoli;
    void risolvi(bipolo bp0);
};