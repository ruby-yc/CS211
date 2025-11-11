#include <iostream>
using namespace std;

const int N = 8;
int q[N];  
int numSolutions = 0;

// Check if safe
bool isSafe(int col, int row) {
    for (int i = 0; i < col; i++) {
        if (q[i] == row || abs(q[i] - row) == abs(i - col)) {
            return false;
        }
    }
    return true;
}

int main() {
    int col = 0;  
    
    // Initialize array to -1 (no queen placed)
    for (int i = 0; i < N; i++) {
        q[i] = -1;
    }
    
    while (col >= 0) {
        // If we've placed all queens, print sol
        if (col == N) {
            numSolutions++;
            cout << "Solution #" << numSolutions << ":\n";
            
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (q[j] == i) {
                        cout << "Q ";
                    } else {
                        cout << ". ";
                    }
                }
                cout << "\n";
            }
            cout << "\n";
            
            // Backtrack
            col--;
            if (col >= 0) {
                q[col]++;  // Try next row
            }
            continue;
        }
        
        // If starting this column, initialize to 0
        if (q[col] == -1) {
            q[col] = 0;
        }
        
        while (q[col] < N && !isSafe(col, q[col])) {
            q[col]++;
        }
        
        if (q[col] < N) {
            // Valid position found, move to next column
            col++;
            if (col < N) {
                q[col] = -1; 
            }
        } else {
            q[col] = -1;
            col--;
            if (col >= 0) {
                q[col]++;  // Try next row in previous column
            }
        }
    }
    
    cout << "Total solutions: " << numSolutions << endl;
    return 0;
}