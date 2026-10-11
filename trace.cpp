#include <iostream>
#include <vector>
using namespace std;

int main() {
    int D = 4;
    long long n = 3;
    
    int total_nodes = (1 << D) - 1;
    int leaf_count = 1 << (D - 1);
    
    cout << "D=" << D << ", n=" << n << endl;
    cout << "total_nodes=" << total_nodes << ", leaf_count=" << leaf_count << endl;
    
    // Initialize all switches to closed (0)
    vector<int> switches(total_nodes + 1, 0); // 1-indexed
    
    int last_position = 0;
    
    // Simulate all n balls with detailed tracing
    for (long long ball = 1; ball <= n; ball++) {
        cout << "\nBall " << ball << ":" << endl;
        int current = 1; // Start at root
        
        while (true) {
            cout << "  At node " << current;
            
            // Check if current node is a leaf (no children)
            if (current * 2 > total_nodes) {
                cout << " (leaf) - toggle to " << (1 - switches[current]) << endl;
                // This is a leaf node, toggle its state
                switches[current] = 1 - switches[current];
                last_position = current;
                break;
            }
            
            cout << " (switch=" << switches[current] << ") - ";
            if (switches[current] == 0) {
                // Switch is closed, open it and go left
                switches[current] = 1;
                cout << "open, go left to " << (current * 2) << endl;
                current = current * 2; // Go to left child
            } else {
                // Switch is open, close it and go right
                switches[current] = 0;
                cout << "close, go right to " << (current * 2 + 1) << endl;
                current = current * 2 + 1; // Go to right child
            }
        }
        
        cout << "  Ball ends at position " << last_position << endl;
    }
    
    cout << "\nFinal leaf states:" << endl;
    for (int i = 0; i < leaf_count; i++) {
        int leaf_pos = (1 << (D - 1)) + i;
        cout << "  Leaf " << leaf_pos << ": " << switches[leaf_pos] << endl;
    }
    
    cout << "\nExpected output:" << endl;
    cout << last_position << endl;
    for (int i = 0; i < leaf_count; i++) {
        int leaf_pos = (1 << (D - 1)) + i;
        cout << switches[leaf_pos];
        if (i < leaf_count - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}