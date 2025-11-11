#include <iostream>
using namespace std;

int main() {
    int numSolutions = 0; // Initialize numSolutions to 0
    int q[8][8] = {};  // Initialize the board to 0
    int r = 0, c = 0;  // Start in the 1st row, 1st column
    q[r][c] = 1;       // Place the first queen on the upper left corner

nextCol:
      c++; // Move to the next column
      if(c==8){// If you passed the last column
            goto print;//goto print
      }
      r=-1;// Otherwise start at the "TOP" of the column

nextRow:
      r++;// Move to the next row
      if(r==8){// If you have passed the end of the column
            goto backtrack;//goto backtrack
      }

      // row test _______
      for(int i=0; i<c; i++){// for each square to the left of the current square
            if(q[r][i]==1){//if there is a queen on that square
                  goto nextRow;
            }
      }

      // upper-left diagonal test_______
      for (int i = 1; (r-i>=0)&& (c-i>=0); i++){ // End the loop when you are above or left of the chessboard
            if(q[r-i][c-i]==1){  //if there is a queen i spots above and left of the current square
                  goto nextRow;
            }
      }

      // lower-left diagonal test ________
      for (int i=1; (r+i<8)&&(c-i>=0); i++){  // for (int i = 1; ...; i++) // End the loop when you are below or left of the chessboard
           if(q[r+i][c-i]==1){ //if (there is a queen i spots below and left of the current square)
                  goto nextRow;
           }
      }

      q[r][c]=1;  // Assign this current position to a queen
      goto nextCol;

backtrack:
      c--;// Move to the previous column

      if(c==-1){// if (you have moved to the left of the chessboard)
            return 0;//exit the program
      }

      // Find the square in the column with a queen in it and set r to the row number of that square
      r=0;
      while(q[r][c]!=1){
            r++;
      }

      q[r][c]=0;// Remove the queen from the current square
      goto nextRow;

print:
      numSolutions++;
      cout << "Solution #" << numSolutions << ":\n";
      for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                  cout << q[i][j];
            }
            cout << "\n";
      }
      goto backtrack; // Use a nested loop to print the chessboard

}

