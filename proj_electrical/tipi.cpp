#include "tipi.hpp"
/*
void circuito::risolvi(bipolo bp0) {
    for (bipolo bp : bipoli) {
        if((bp.nodo1.nome == bp0.nodo1.nome && bp.nodo2.nome == bp0.nodo2.nome) || (bp.nodo2.nome == bp0.nodo1.nome && bp.nodo1.nome == bp0.nodo2.nome))  {
            auto it = find(bp0.paralleli.begin(), bp0.paralleli.end(), bp);
            if(it == bp0.paralleli.end()) { //non trovato in parallelo
                bp0.paralleli.push_back(bp);
                bp.voltaggio = bp0.voltaggio; //parallelo, stesso voltaggio
            }
            if(bp.nodo1.nome == bp0.nodo1.nome || bp.nodo2.nome == bp0.nodo2.nome || bp.nodo1.nome == bp0.nodo2.nome || bp.nodo2.nome == bp.nodo1.nome) {
                auto its = find(bp0.serie[bp0.nodo1].begin(), bp0.serie[bp0.nodo1].end(), bp);
                if(its == bp0.serie[bp0.nodo1].end()) { //non trovato in serie 1
                    bp0.serie[bp0.nodo1].push_back(bp);
                }
                auto its = find(bp0.serie[bp0.nodo2].begin(), bp0.serie[bp0.nodo2].end(), bp);
                if(its == bp0.serie[bp0.nodo2].end()) { //non trovato in serie 2
                    bp0.serie[bp0.nodo2].push_back(bp);
                }
                if(bp0.serie[bp0.nodo1].size() == 1) { //"vera" serie, sommo correnti

                }
            }
        }
    }
}
*/

void circuito::aggiungiBipolo(nodo n1, bipolo b, nodo n2) {
    grafo[n1].push_back(make_pair(b, n2));
    grafo[n2].push_back(make_pair(b, n1));
}

void circuito::attraversaDaSx(nodo inizio) {
    //DFS algoritmo
    //unordered_map<nodo, bool> nodi_visitati;
    set<nodo> nodi_visitati;
    dfs(inizio, nodi_visitati);
}

void circuito::dfs(nodo att, set<nodo>& visitati) {
    visitati.insert(att);

    for(const auto& connessione : grafo[att]) {
        bipolo bp = connessione.first;
        nodo next = connessione.second;
        if(visitati.find(next) == visitati.end()) {
        //CALCOLI
            dfs(next, visitati);
        }
    }
}