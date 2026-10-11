#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int D;
    long long n;
    cin >> D >> n;
    
    int total_nodes = (1 << D) - 1;
    int leaf_count = 1 << (D - 1);
    
    // Initialize all switches to closed (0)
    vector<int> switches(total_nodes + 1, 0); // 1-indexed
    
    int last_position = 0;
    
    // For efficiency with large n, we need to optimize
    // If n is too large, we can't simulate all balls
    // But we can use the fact that the k-th ball's path can be determined
    // using binary representation
    
    if (n <= 1000000) {
        // For smaller n, simulate directly
        for (long long ball = 1; ball <= n; ball++) {
            int current = 1; // Start at root
            
            while (true) {
                // Check if current node is a leaf (no children)
                if (current * 2 > total_nodes) {
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
    } else {
        // For large n, use optimized approach
        // First, simulate a reasonable number of balls to establish pattern
        long long simulate_count = 100000;
        for (long long ball = 1; ball <= simulate_count; ball++) {
            int current = 1; // Start at root
            
            while (true) {
                // Check if current node is a leaf (no children)
                if (current * 2 > total_nodes) {
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
        
        // For the remaining balls, just find the last position
        // using binary representation method
        for (long long ball = simulate_count + 1; ball <= n; ball++) {
            int current = 1; // Start at root
            
            while (true) {
                // Check if current node is a leaf (no children)
                if (current * 2 > total_nodes) {
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