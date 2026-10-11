#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int D;
    long long n;
    cin >> D >> n;
    
    int total_nodes = (1 << D) - 1;
    int leaf_count = 1 << (D - 1);
    
    // Initialize all switches to closed (0)
    vector<int> switches(total_nodes + 1, 0); // 1-indexed
    
    int last_position = 0;
    
    // For efficiency, if n is too large, we need a different approach
    // But for now, let's try the simulation approach with optimization
    // We can break early if we detect patterns
    
    // Simulate all n balls
    for (long long ball = 1; ball <= n; ball++) {
        int current = 1; // Start at root
        
        while (current <= total_nodes) {
            // Check if current node is a leaf
            if (current > (total_nodes / 2)) {
                // This is a leaf node, toggle its state
                switches[current] = 1 - switches[current];
                last_position = current;
                break;
            }
            
            if (switches[current] == 0) {
                // Switch is closed, open it and go left
                switches[current] = 1;
                current = current * 2; // Go to left child
            } else {
                // Switch is open, close it and go right
                switches[current] = 0;
                current = current * 2 + 1; // Go to right child
            }
        }
    }
    
    // Output last position
    cout << last_position << endl;
    
    // Output leaf node states (from left to right)
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