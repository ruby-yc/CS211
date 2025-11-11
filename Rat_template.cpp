// Rat class i.e. a class for rational numbers
#include <iostream>
#include <cmath>
using namespace std;

class Rat{
private:
   int n;
   int d;
   
public:
   // default constructor
    Rat() : n(0), d(1) {}

    // 2 parameter constructor
    Rat(int num, int den) : n(num), d(den) {
        if (d == 0) throw invalid_argument("Denominator cannot be zero");
        reduce();
    }

    // conversion constructor (int to Rat)
    Rat(int whole) : n(whole), d(1) {}

    // accessor functions
    int getN() const { return n; }
    int getD() const { return d; }

    void setN(int num) { n = num; reduce(); }
    void setD(int den) {
        if (den == 0) throw invalid_argument("Denominator cannot be zero");
        d = den;
        reduce();
    }

   Rat operator+(Rat r){
      return Rat(n * r.d + r.n * d, d * r.d);
   }
   
   Rat operator-(Rat r){
      return Rat(n * r.d - r.n * d, d * r.d);
   }
   
   Rat operator*(Rat r){
      return Rat(n * r.n, d * r.d);
   }
   
   Rat operator/(Rat r){
       if (r.n == 0) throw invalid_argument("Division by zero");
        return Rat(n * r.d, d * r.n);
   }
   
   // Reduce the Rat to lowest terms
   void reduce(){
      if (d < 0) { n = -n; d = -d; }
        int g = gcd(abs(n), abs(d));
        n /= g;
        d /= g;
    }
   
   
   // Calculate the GCD (Euclid's algorithm)
   int gcd(int n, int d){
      while (d != 0) {
            int temp = n % d;
            n = d;
            d = temp;
        }
        return n;
    }
   

   // 2 overloaded i/o operators
   friend ostream& operator<<(ostream& os, Rat r);
   friend istream& operator>>(istream& is, Rat& r);
}; //end Rat

// operator<<() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts.
// 3/2 is printed as 1 1/2
// 1/2 is printed as 1/2
// 2/1 is printed as 2
// 0/1 is printed as 0
// Negative numbers are printed the same way, but beginning with a minus sign
ostream& operator<<(ostream& os, Rat r){
   int whole = r.n / r.d;
    int rem = abs(r.n % r.d);

    if (r.n == 0)
        os << "0";
    else if (abs(r.n) < r.d)
        os << r.n << "/" << r.d;
    else if (rem == 0)
        os << whole;
    else
        os << whole << " " << rem << "/" << r.d;

    return os;

}

// operator>>() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts.
istream& operator>>(istream& is, Rat& r){
    char slash;
    is >> r.n >> slash >> r.d;
    if (r.d == 0) throw invalid_argument("Denominator cannot be zero");
    r.reduce();
    return is;
}

int main() {
   Rat r1(5, 2), r2(3, 2);
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   cout << endl;
   
   r1 = r2;
   r2 = r1 * r2;
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   cout << endl;
   
   r1 = r2 + r1 * r2 / r1;
   r2 = r2 + r1 * r2 / r1;
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   
   return 0;
}
