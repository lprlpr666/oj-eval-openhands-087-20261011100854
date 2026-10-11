#include <iostream>
#include <vector>
using namespace std;

int main() {
    int D = 4;
    int total_nodes = (1 << D) - 1;
    
    cout << "D=" << D << ", total_nodes=" << total_nodes << endl;
    cout << "Leaf nodes are: ";
    for (int i = 1; i <= total_nodes; i++) {
        if (i * 2 > total_nodes) {
            cout << i << " ";
        }
    }
    cout << endl;
    
    cout << "Leaves from 2^(D-1): ";
    for (int i = (1 << (D-1)); i <= total_nodes; i++) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}