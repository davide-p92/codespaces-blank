#include <iostream>
#include <string>
#include <memory>

using namespace std;

enum class Tipo {
    Resistenza = 1
};

// Class representing a bipolo (electrical component)
class bipolo {
public:
    int id;
    string nome;
    Tipo tipo;
    float valore;  // resistance (Ohms)

    bipolo(int id, const string& nome, Tipo tipo, float valore)
        : id(id), nome(nome), tipo(tipo), valore(valore) {}
};

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
unique_ptr<ExpressionNode> buildExpressionTree(int numComponents) {
    unique_ptr<ExpressionNode> root = nullptr;

    for (int i = numComponents; i > 0; --i) {
        float resistanceValue;
        cout << "Enter resistance for resistor " << i << ": ";
        cin >> resistanceValue;

        // Create a new resistor (bipolo)
        bipolo resistor(i, "Resistor" + to_string(i), Tipo::Resistenza, resistanceValue);
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

    return root;  // Return the root of the tree
}

int main() {
    int numResistors;
    cout << "Enter the number of resistors: ";
    cin >> numResistors;

    // Build the tree based on user input
    unique_ptr<ExpressionNode> tree = buildExpressionTree(numResistors);

    // Evaluate the total resistance
    float totalResistance = tree->evaluate();
    cout << "The total equivalent resistance of the circuit is: " << totalResistance << " Ohms" << endl;

    return 0;
}
