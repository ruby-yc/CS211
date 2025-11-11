//add sum for big int
#include <iostream>
#include <string>
using namespace std;

int main() {
    string num1, num2;
    cout << "Enter 2 integers (up to 100 digits): ";
    cin >> num1 >> num2;
    
    string result = "";
    int carry = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    
    while (i >= 0  ||  j >= 0  ||  carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        
        result = char(sum % 10 + '0') + result;
        carry = sum / 10;
    }
    
    cout << "Sum: " << result << endl;
    
    return 0;
}