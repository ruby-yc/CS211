#include<iostream>
using namespace std;

//avoid queens conflict
bool check(int q[8][8]){
    for(int c=0; c<8; c++){
        int r=0;
        while(q[r][c] != 1) r++;  // find which row is the queen in
        
        // row check
        for(int i=0; i<c; i++)
            if(q[r][i] == 1) return false;
        
        // up diagonal check
        for(int i=1; (r-i)>=0 && (c-i)>=0; i++)
            if(q[r-i][c-i] == 1) return false;

        // down diagonal check
        for(int i=1; (r+i)<8 && (c-i)>=0; i++)
            if(q[r+i][c-i] == 1) return false;
    }
    return true;
}

//output current solution
void print(int q[8][8]){
    static int count = 0;
    count++;
    cout << "Solution #" << count << ":\n";
    for(int r=0; r<8; r++){
        for(int c=0; c<8; c++)
            cout << q[r][c] << " ";
        cout << endl;
    }
    cout << endl;
}

int main(){
    int q[8][8] = {0};

    // list all (try all posible combinations)
    for(int i0=0; i0<8; i0++){
        for(int i1=0; i1<8; i1++){
            for(int i2=0; i2<8; i2++){
                for(int i3=0; i3<8; i3++){
                    for(int i4=0; i4<8; i4++){
                        for(int i5=0; i5<8; i5++){
                            for(int i6=0; i6<8; i6++){
                                for(int i7=0; i7<8; i7++){
                                    // clear the board
                                    for(int r=0; r<8; r++)
                                        for(int c=0; c<8; c++)
                                            q[r][c] = 0;

                                    // place the queen
                                    q[i0][0] = 1;
                                    q[i1][1] = 1;
                                    q[i2][2] = 1;
                                    q[i3][3] = 1;
                                    q[i4][4] = 1;
                                    q[i5][5] = 1;
                                    q[i6][6] = 1;
                                    q[i7][7] = 1;

                                    if (check(q)) print(q);
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

