#include <iostream>
using namespace std;

int main() {
    int i = 1;
    int square;
    
    while (true) {
        square = i * i;
        
        //if both last digis are odds
        int lastDigit = square % 10;
        int secondLastDigit = (square / 10) % 10;
        
        if (lastDigit % 2 == 1 && secondLastDigit % 2 == 1) {
            cout << "First perfect square with odd last two digits: " << square << endl;
            cout << square << " = " << i << "^2" << endl;
            
            int root = sqrt(square);
            cout << "Verification: " << root << " * " << root << " = " << root * root << endl;
            break;
        }
        i++;
    }
    
    return 0;
}