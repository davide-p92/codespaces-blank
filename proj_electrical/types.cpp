#include <iostream>
#include <vector>
#include <map>
#include <Eigen/Dense>  // Include the Eigen library for solving linear systems

using namespace std;
using namespace Eigen;

enum class Tipo {
    Resistenza = 1,
    SorgenteV = 2,
    SorgenteI = 3
};

// Class representing a bipolo (resistor or voltage source)
class bipolo {
public:
    int id;
    string nome;
    Tipo tipo;
    float valore;  // Resistance in ohms for resistors, Voltage for voltage sources
    int nodo1;     // First node connected to the bipolo
    int nodo2;     // Second node connected to the bipolo

    bipolo(int id, const string& nome, Tipo tipo, float valore, int n1, int n2)
        : id(id), nome(nome), tipo(tipo), valore(valore), nodo1(n1), nodo2(n2) {}
};

class Circuito {
public:
    vector<bipolo> bipoli;  // Vector of bipoles (resistors, voltage sources)
    int numNodi;            // Total number of nodes in the circuit

    Circuito(int numNodi) : numNodi(numNodi) {}

    void aggiungiBipolo(int id, const string& nome, Tipo tipo, float valore, int n1, int n2) {
        bipoli.emplace_back(id, nome, tipo, valore, n1, n2);
    }

    void risolviCircuitoKir() {
        
    }

    void risolviCircuitoMat() {
        MatrixXd G = MatrixXd::Zero(numNodi, numNodi);  // Conductance matrix (G)
        VectorXd I = VectorXd::Zero(numNodi);           // Current vector (I)
        map<int, float> nodalVoltages;                  // Map to store the voltages of each node

        // Build the conductance matrix (G) and the current vector (I)
        for (const auto& b : bipoli) {
            if (b.tipo == Tipo::Resistenza) {
                // Resistor: add conductance (1/R) to the G matrix
                float conductance = 1.0 / b.valore;
                if (b.nodo1 != 0) G(b.nodo1, b.nodo1) += conductance; //G(b.nodo1 - 1, b.nodo1 - 1)
                if (b.nodo2 != 0) G(b.nodo2, b.nodo2) += conductance; //...
                if (b.nodo1 != 0 && b.nodo2 != 0) {
                    G(b.nodo1, b.nodo2) -= conductance;
                    G(b.nodo2, b.nodo1) -= conductance;
                }
            } else if (b.tipo == Tipo::SorgenteI) {
                // Voltage source: modify the current vector (I)
                if (b.nodo1 != 0) I(b.nodo1) -= b.valore;  // Apply the voltage difference
                if (b.nodo2 != 0) I(b.nodo2) += b.valore;
            } else if (b.tipo == Tipo::SorgenteV) {
                
            }
            cout << "G: \n";
            cout << G << endl;
            cout << "I: \n";
            cout << I << endl;
        }

        // Solve the linear system G * V = I for nodal voltages
        VectorXd V = G.fullPivLu().solve(I);

        // Store the computed nodal voltages
        for (int i = 0; i < V.size(); ++i) {
            nodalVoltages[i] = V(i);  // Node numbering starts from 1
        }

        // Output the voltages at each node
        cout << "Nodal Voltages:" << endl;
        for (const auto& [node, voltage] : nodalVoltages) {
            cout << "Voltage at node " << node << ": " << voltage << " V" << endl;
        }

        // Output the voltage across each bipolo
        for (const auto& b : bipoli) {
            if (b.tipo == Tipo::Resistenza) {
                float voltageDrop = nodalVoltages[b.nodo1] - nodalVoltages[b.nodo2];
                cout << "Voltage across " << b.nome << ": " << voltageDrop << " V" << endl;
            }
        }
    }
};

int main() {
    int numNodi;
    cout << "Enter the number of nodes in the circuit: ";
    cin >> numNodi;

    Circuito circuito(numNodi);

    int numResistors;
    cout << "Enter the number of resistors: ";
    cin >> numResistors;

    for (int i = numResistors; i > 0; --i) {
        float resistance;
        int nodo1, nodo2;
        cout << "Enter resistance (in ohms) for resistor " << i << ": ";
        cin >> resistance;
        cout << "Enter the two nodes it connects (node1 node2): ";
        cin >> nodo1 >> nodo2;

        circuito.aggiungiBipolo(i + 1, "Resistor " + to_string(i), Tipo::Resistenza, resistance, nodo1, nodo2);
    }

    int numVoltageSources;
    cout << "Enter the number of voltage sources: ";
    cin >> numVoltageSources;

    for (int i = numVoltageSources; i > 0; --i) {
        float voltage;
        int nodo1, nodo2;
        cout << "Enter voltage (in volts) for voltage source " << i << ": ";
        cin >> voltage;
        cout << "Enter the two nodes it connects (node1 node2): ";
        cin >> nodo1 >> nodo2;

        circuito.aggiungiBipolo(numResistors + i, "Voltage Source " + to_string(i), Tipo::SorgenteV, voltage, nodo1, nodo2);
    }

    // Solve the circuit for node voltages and voltage drops across each resistor
    circuito.risolviCircuitoMat();

    return 0;
}
