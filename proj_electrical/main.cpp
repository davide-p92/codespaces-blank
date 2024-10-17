#include "tipi.hpp"

int main() {
    nodo n1(1), n2(2), n3(3), n4(4), n0(0);
    bipolo b1(1, "R1", Tipo::Resistenza, n1, n2);
    bipolo b2(2, "R2", Tipo::Resistenza, n0, n2);
    bipolo b3(3, "R3", Tipo::Resistenza, n2, n3);
    bipolo b4(4, "R4", Tipo::Resistenza, n2, n4);
    bipolo b5(5, "R5", Tipo::Resistenza, n0, n4);
    bipolo b6(6, "R6", Tipo::Resistenza, n0, n4);
    bipolo b7(7, "E1", Tipo::SorgenteV, n0, n1);
    bipolo b8(8, "E2", Tipo::SorgenteV, n0, n3);
    circuito c(1);
    c.aggiungiBipolo(b1);
    c.aggiungiBipolo(b2);
    c.aggiungiBipolo(b3);
    c.aggiungiBipolo(b4);
    c.aggiungiBipolo(b5);
    c.aggiungiBipolo(b6);
    c.aggiungiBipolo(b7);
    c.aggiungiBipolo(b8);
    c.attraversaDaSx(n1);
}