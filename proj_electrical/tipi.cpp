#include "tipi.hpp"

void circuito::risolvi(bipolo bp0) {
    for (bipolo bp : bipoli) {
        if((bp.nodo1.nome == bp0.nodo1.nome && bp.nodo2.nome == bp0.nodo2.nome) || (bp.nodo2.nome == bp0.nodo1.nome && bp.nodo1.nome == bp0.nodo2.nome))  {
            auto it = find(bp0.paralleli.begin(), bp0.paralleli.end(), bp);
        }
    }
}