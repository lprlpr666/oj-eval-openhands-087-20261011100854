#include <iostream>
#include <vector>
using namespace std;

int main() {
    int D;
    long long n;
    cin >> D >> n;
    
    int total_nodes = (1 << D) - 1;
    int leaf_count = 1 << (D - 1);
    
    // Initialize all switches to closed (0)
    vector<int> switches(total_nodes + 1, 0);
    
    int last_position = 0;
    
    // Simulate each ball
    for (long long k = 1; k <= n; k++) {
        int node = 1;
        
        while (node <= total_nodes) {
            // If this is a leaf node
            if (node > total_nodes / 2) {
                switches[node] ^= 1;  // Toggle leaf switch
                last_position = node;
                break;
            }
            
            // Internal node: check switch state
            if (switches[node] == 0) {
                switches[node] = 1;  // Open switch
                node = node * 2;      // Go left
            } else {
                switches[node] = 0;  // Close switch
                node = node * 2 + 1;  // Go right
            }
        }
    }
    
    cout << last_position << endl;
    
    // Output leaf states
    for (int i = 0; i < leaf_count; i++) {
        int leaf = (1 << (D - 1)) + i;
        cout << switches[leaf];
        if (i < leaf_count - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}