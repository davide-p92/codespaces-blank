#include "classes.cpp"
    

int main() {
    int numNodi;
    cout << "Enter the number of nodes in the circuit: ";
    cin >> numNodi;

    int numResistors;
    cout << "Enter the number of resistors: ";
    cin >> numResistors;
/*
    for (int i = numResistors; i > 0; --i) {
        float resistance;
        int nodo1, nodo2;
        cout << "Enter resistance (in ohms) for resistor " << i << ": ";
        cin >> resistance;
        cout << "Enter the two nodes it connects (node1 node2): ";
        cin >> nodo1 >> nodo2;

        circuito.aggiungiBipolo(i + 1, "Resistor " + to_string(i), Tipo::Resistenza, resistance, nodo1, nodo2);
    }
*/
    unique_ptr<ExpressionNode> tree;
    Circuito circuito(numNodi);
    pair<unique_ptr<ExpressionNode>, unique_ptr<Circuito>> p = buildExpressionTree(numResistors);
    tree = move(p.first);
    
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
    //circuito.risolviCircuitoMat();

    // Build the tree based on user input
    //unique_ptr<ExpressionNode> tree = buildEx

    // Evaluate the total resistance
    if(tree != nullptr) {
    	float totalResistance = tree->evaluate();
    	cout << "The total equivalent resistance of the circuit is: " << totalResistance << " Ohms" << endl;
    } else {
    	cout << "Error. tree is not initialized." << endl;
    }

    return 0;
}
