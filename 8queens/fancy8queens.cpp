#include <iostream>
using namespace std;

typedef char box[5][7];
box bb, wb, wq, bq; 
box *board[8][8];


bool check(int q[8]) {
    for (int c = 0; c < 8; c++) {
        for (int i = 0; i < c; i++) {
        if (q[i] == q[c]) return false;
        else if ((c - i) == abs(q[c] - q[i])) return false;
        
    }
    }
return true;
}

void print(int q[8]) {
    for (int i = 0; i < 8; i++) {
        int row = q[i]; 
        if ((row + i) % 2 == 0) {
            board[row][i] = &wq; 
        } else {
            board[row][i] = &bq; 
    }
}

//print up border
cout << " ";
for (int i = 0; i < 7 * 8; i++) cout << char(196);
cout << endl;

for (int i = 0; i < 8; i++) {
    for (int k = 0; k < 5; k++) {
    cout << " " << char(179); // left boarder
        for (int j = 0; j < 8; j++) {
            for (int l = 0; l < 7; l++) {
            cout << (*board[i][j])[k][l];
            }
        }
        cout << char(179) << endl;
    }
}

    // print lower boarder
    cout << " ";
    for (int i = 0; i < 7 * 8; i++) cout << char(196);
    cout << endl;

    // reset the board
    //fill board with pointers to bb and wb in alternate position
    for (int i = 0; i < 8; i++) {
         int row = q[i];
        if ((row + i) % 2 == 0) {
            board[row][i] = &wb;
        } else {
            board[row][i] = &bb;
        }
    }
}

//fill in bb= blackbox and wb=whitebox
int main() {
for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 7; j++) {
        wb[i][j] = ' ';
        bb[i][j] = char(219);
    }
}

// initiate queen box
for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 7; j++) {
        wq[i][j] = ' ';  
        bq[i][j] = char(219); 
    }
}
//put queens in the middle 
wq[2][3] = 'Q';
bq[2][3] = 'Q';

//set initial board
for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
        if ((i + j) % 2 == 0) board[i][j] = &wb;
        else board[i][j] = &bb;
    }
}

// solve 8 queens
int q[8];
for (int i0 = 0; i0 < 8; i0++) {
q[0] = i0;
    for (int i1 = 0; i1 < 8; i1++) {
    q[1] = i1;
        for (int i2 = 0; i2 < 8; i2++) {
        q[2] = i2;
            for (int i3 = 0; i3 < 8; i3++) {
            q[3] = i3;
                for (int i4 = 0; i4 < 8; i4++) {
                q[4] = i4;
                   for (int i5 = 0; i5 < 8; i5++) {
                    q[5] = i5;
                        for (int i6 = 0; i6 < 8; i6++) {
                         q[6] = i6;
                            for (int i7 = 0; i7 < 8; i7++) {
                            q[7] = i7;
                                if (check(q)) {
                                print(q);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

return 0;
}