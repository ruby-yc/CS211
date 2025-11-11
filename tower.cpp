#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> t[3];
   int n;
   cout << "Please enter the number of rings to move: ";
   cin >> n;
   cout << endl;
   // The initial value of to depends on whether n is odd or even
   int from = 0, to =(n%2==1)? 1:2, candidate = 1, move = 0;

   // Initialize the towers
   //tower 0 will have all disks from largest n to smallest l, and plus the padding (n+1)) on bottom
   for(int i = n + 1; i >= 1; --i)
      t[0].push_back(i);
   //tower 1 and 2 will each have only padding value
   t[1].push_back(n+1);
   t[2].push_back(n+1);

   while (t[1].size() < n+1) { // while t[1] does not contain all of the rings
      cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n";

      // Move the ring from the "from tower" to the "to tower" (first copy it, then delete it from the "from tower")
      t[to].push_back(t[from].back()); //put the top disk from "from" to "to"
      t[from].pop_back();   //remove the top one

      // from = the index of the tower with the smallest ring that has not just been moved: (to+1)%3 or (to+2)%3
      //pick the smaller disk from 2 tower
      int next1 = (to + 1) % 3;
      int next2 = (to + 2) % 3;
      if (t[next1].back()< t[next2].back())
         from = next1;
      else
         from = next2;

      // candidate = the ring on top of the t[from] tower
      candidate = t[from].back();

      // to = the index of the closest tower on which the candidate can be placed: (from+1)%3 or (from+2)%3
      // (compare the candidate with the ring on the closer tower; which tower is "closer" depends on whether n is odd or even)
      int closest = (n % 2 == 1) ? (from + 1) % 3 : (from + 2) % 3;
      int farther  = (n % 2 == 1) ? (from + 2) % 3 : (from + 1) % 3;
      if (t[closest].back() > candidate) { // if candidate can be placed on closest tower
         if (t[closest].back() > candidate)
             to = closest;
         else
             to = farther;
     }
     else { // else, candidate must be placed on farther tower
         if (t[farther].back() > candidate)
             to = farther;
         else
             to = closest;
     }
      // you can do this without the extra if / else statement by creating a variable called
      // closest which will be assigned (from+1)%3 or (from+2)%3 depending on if n is even or odd
      // try to use a ternary operator to assign it.
   }
   return 0;
}
