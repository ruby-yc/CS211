//cunyid:24455630
#include<iostream>
#include<cmath>
using namespace std;

bool ok(int q[], int c) {
    // Adjacency table: each row shows the neighbors of box c
    // -1 is the sentinel value marking the end of neighbors
    static int adj_table[8][5] = {
        {-1},           // Box 0 has no neighbors
        {0, -1},        // Box 1 neighbors: 0
        {1, -1},        // Box 2 neighbors: 1
        {0, 1, 2, -1},  // Box 3 neighbors: 0, 1, 2
        {1, 2, 3, -1},  // Box 4 neighbors: 1, 2, 3
        {2, 4, -1},     // Box 5 neighbors: 2, 4
        {0, 3, 4, -1},  // Box 6 neighbors: 0, 3, 4
        {3, 4, 5, 6, -1} // Box 7 neighbors: 3, 4, 5, 6
    };

    // 1. REPETITION CHECK
    // Is the proposed number in q[c] repeating one of the previously placed numbers?
    // (Same as the 8-Queen row check)
    for (int i = 0; i < c; i++) {
        if (q[i] == q[c]) {
            return false;  // Found a duplicate
        }
    }

    // 2. CONSECUTIVE NUMBER CHECK
    // Is the proposed number in q[c] a consecutive number to its neighbors?
    
    // Checking through all c's neighbors from the first neighbor until we hit the sentinel value -1
    int i = 0;
    int neighbor_box = adj_table[c][i];
    
    while (neighbor_box != -1) {
        // Check if value at neighbor_box and q[c] are consecutive
        // Two numbers are consecutive if their absolute difference is 1
        if (abs(q[neighbor_box] - q[c]) == 1) {
            return false;  // Consecutive numbers found
        }
        // Move to the next neighbor
        i++;
        neighbor_box = adj_table[c][i];
    }

    return true;  // All checks passed
}

void print(int cross[]) {
    // everytime this function is called, count will not reset to 0 since it is static
    // static means the variable is allocated only once during the runtime of the program
    static int count = 0;
    cout << "Solution number: " << ++count << endl;
    cout << " " << cross[1] << cross[2] << endl;
    cout << cross[0] << cross[3] << cross[4] << cross[5] << endl;
    cout << " " << cross[6] << cross[7] << endl;
    cout << endl;
    return;
}

// SAME MAIN METHOD AS THE 8 QUEENS NO GOTOS program
int main() {
    int q[8] = {};   // Initialize the array to 0
    int c = 0;       // Start in the 1st box (box 0)

    // Main loop: continues until we backtrack past the first box
    while (c >= 0) {
        // If you have passed the last box (placed all 8 numbers)
        if (c == 8) {
            // Call the print function and backtrack
            print(q);
            c--;
            if (c >= 0) {
                q[c]++;  // Try next value in previous box
            }
            continue;
        }

        // If starting this box, initialize value to one before the first possible value
        if (q[c] == 0) {
            q[c] = 1;  // Start from 1 (values are 1-8)
        }

        // Inner loop: try values for current box
        while (c >= 0) {
            // If you have passed the end of the box (tried all values 1-8)
            if (q[c] > 8) {
                // Backtrack
                q[c] = 0;  // Reset this box
                c--;       // Go back to previous box
                if (c >= 0) {
                    q[c]++;  // Try next value in previous box
                }
            }
            // Else If the ok function returns true, break out of this loop to move on from the outer loop
            else if (ok(q, c)) {
                // Valid position found, move to next box
                c++;
                if (c < 8) {
                    q[c] = 0;  // Initialize next box
                }
                break;  // Exit inner while loop
            }
            // Value not valid, try next value
            else {
                q[c]++;
            }
        }
    }

    return 0;
}