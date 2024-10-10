#include "tipi.hpp"

int main() {
    nodo n1(1), n2(2);
    bipolo b(1, "Resistenza1", Tipo::Resistenza, n1, n2);
    nodo n3(3);
    bipolo b2(2, "Vs", Tipo::SorgenteV, n2, n3);
}