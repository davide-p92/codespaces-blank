#include <iostream>
#include <string>

class Animale {
    public:
    std::string specie;
    std::string nome;
};

class Cane : public Animale {
    public:
    Cane(std::string nome);
    void abbaia();
};

Cane::Cane(std::string nome) {
    specie = "Cane";
    this->nome = nome;
}

void Cane::abbaia() {
    std::cout << "Bau bau mi chiamo " << nome << " e sono un " << specie << std::endl;
}