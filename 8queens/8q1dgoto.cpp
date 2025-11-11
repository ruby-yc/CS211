#include <iostream>
using namespace std;

const int N = 8;
int q[N];  
int numSolutions = 0;

int main() {
    int col = 0;  // current column
    int row = 0;  // current row to try
    int i;       
    int j;        
    bool safe;    // safety check variable
    
    // Initialize array
    for (i = 0; i < N; i++) {
        q[i] = -1;
    }
    
nextCol:
    // If we've placed all queens, we found a solution
    if (col == N) {
        numSolutions++;
        cout << "Solution #" << numSolutions << ":\n";
        
        // Print 2D representation
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (q[j] == i) {
                    cout << "Q ";
                } else {
                    cout << ". ";
                }
            }
            cout << "\n";
        }
        cout << "\n";
        
       
        col--;
        goto backtrack;
    }
    
    // Try placing queen in this column
    row = 0;
    
tryRow:
    if (row >= N) {
        // No valid row in this column, backtrack
        col--;
        goto backtrack;
    }
    
    // Check if this position is safe
    safe = true;
    for (i = 0; i < col; i++) {
        // Check row conflict
        if (q[i] == row) {
            safe = false;
            goto notSafe;
        }
        
        // Check diagonal conflict
        if (abs(q[i] - row) == abs(i - col)) {
            safe = false;
            goto notSafe;
        }
    }
    
notSafe:
    if (!safe) {
        // Try next row
        row++;
        goto tryRow;
    }
    
    // Place queen at this position
    q[col] = row;
    col++;
    goto nextCol;
    
backtrack:
    if (col < 0) {
        // All solutions found
        goto done;
    }
    
    // Try next row in previous column
    row = q[col] + 1;
    goto tryRow;
    
done:
    cout << "Total solutions: " << numSolutions << endl;
    return 0;
}