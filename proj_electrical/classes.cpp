#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <Eigen/Dense>  // Include the Eigen library for solving linear systems
#include <string>
#include <memory>


using namespace std;

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

    bool operator<(const bipolo& oth) const {
    	return this->id < oth.id;
    }

    bipolo(int id, const string& nome, Tipo tipo, float valore, int n1, int n2)
        : id(id), nome(nome), tipo(tipo), valore(valore), nodo1(n1), nodo2(n2) {}
};

class Circuito {
public:
    vector<bipolo> bipoli;  // Vector of bipoles (resistors, voltage sources)
    int numNodi;            // Total number of nodes in the circuit
    
    Circuito() : numNodi(0) {}
    Circuito(int numNodi) : numNodi(numNodi) {}

    void aggiungiBipolo(int id, const string& nome, Tipo tipo, float valore, int n1, int n2) {
        bipoli.emplace_back(id, nome, tipo, valore, n1, n2);
    }
    void aggiungiBipolo(bipolo b) {
    	bipoli.emplace_back(b);
    }

    void risolviCircuitoKir() {
        
    }

    void risolviCircuitoMat() {
        Eigen::MatrixXd G = Eigen::MatrixXd::Zero(numNodi, numNodi);  // Conductance matrix (G)
        Eigen::VectorXd I = Eigen::VectorXd::Zero(numNodi);           // Current vector (I)
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
        Eigen::VectorXd V = G.fullPivLu().solve(I);

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

/*
enum class Tipo {
    Resistenza = 1
};
*/

// Class representing a bipolo (electrical component)
/*class bipolo {
public:
    int id;
    string nome;
    Tipo tipo;
    float valore;  // resistance (Ohms)

    bipolo(int id, const string& nome, Tipo tipo, float valore)
        : id(id), nome(nome), tipo(tipo), valore(valore) {}
};*/

// Base class for an expression node in the binary expression tree
class ExpressionNode {
public:
    virtual float evaluate() const = 0;  // This function will evaluate the total value (resistance, etc.)
    virtual ~ExpressionNode() = default;
};

// Leaf node representing a single component (bipolo)
class BipoloNode : public ExpressionNode {
public:
    bipolo comp;  // Store the bipolo object

    BipoloNode(const bipolo& b) : comp(b) {}

    // Evaluate simply returns the value of the component (resistance)
    float evaluate() const override {
        return comp.valore;
    }
};

// Internal node representing an operation (series or parallel)
class OperationNode : public ExpressionNode {
public:
    unique_ptr<ExpressionNode> left;   // Left subtree (operand)
    unique_ptr<ExpressionNode> right;  // Right subtree (operand)
    char operation;                    // Operation: '+' for series, '|' for parallel

    OperationNode(unique_ptr<ExpressionNode> left, unique_ptr<ExpressionNode> right, char op)
        : left(move(left)), right(move(right)), operation(op) {}

    // Evaluate based on the operation
    float evaluate() const override {
        float leftVal = left->evaluate();
        float rightVal = right->evaluate();

        if (operation == '+') { // Series operation
            return leftVal + rightVal;
        } else if (operation == '|') { // Parallel operation
            return 1 / ((1 / leftVal) + (1 / rightVal));  // Parallel combination formula
        }

        return 0;  // Should not reach here if operations are well-defined
    }
};

// Function to build the tree dynamically based on user input
pair<unique_ptr<ExpressionNode>, unique_ptr<Circuito>> buildExpressionTree(int numComponents) {
    unique_ptr<ExpressionNode> root = nullptr;
    set<bipolo> resistenze;
    set<int> nodi;
    for (int i = numComponents; i > 0; --i) {
        float resistanceValue;
        int node1, node2;
        
        cout << "Enter resistance for resistor " << i << ": ";
        cin >> resistanceValue;
        cout << "Enter node1 for resistor " << i << ": ";
        cin >> node1;
        cout << "Enter node2 for resistor " << i << ": ";
        cin >> node2;
        

        // Create a new resistor (bipolo)
        bipolo resistor(i, "Resistor" + to_string(i), Tipo::Resistenza, resistanceValue, node1, node2);
        nodi.insert(resistor.nodo1);
        nodi.insert(resistor.nodo2);
        resistenze.insert(resistor);
        unique_ptr<ExpressionNode> newNode = make_unique<BipoloNode>(resistor);

        if (root == nullptr) {
            // First component, initialize root
            root = move(newNode);
        } else {
            // For the next components, ask user whether to add in series or parallel
            char operation;
            cout << "How would you like to combine this resistor with the previous one? (+ for series, | for parallel): ";
            cin >> operation;

            // Build an operation node based on user's choice
            root = make_unique<OperationNode>(move(root), move(newNode), operation);
        }
    }
    unique_ptr<Circuito> c = make_unique<Circuito>(nodi.size());
    
    for(auto& elem : resistenze) {
    	c->aggiungiBipolo(elem);
    }

    return make_pair(move(root), move(c));  // Return the root of the tree
}


