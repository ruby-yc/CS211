#include<iostream>
using namespace std;
// pro for proposals
bool ok(int pro[], int c) { // Finish this code
	static int mp[3][3] =
			{ { 0,2,1 },  	 // Man#0's preferences
				{ 0,2,1 },	// Man#1's preferences
				{ 1,2,0 } };	// Man#2's preferences

	static int wp[3][3] =
			{ { 2,1,0 },		// Woman#0's preferences
				{ 0,1,2 },	// Woman#1's preferences
				{ 2,0,1 } };	 // Woman#2's preferences

	for (int i=0; i<c; i++) {
		if( pro[i]==pro[c]) return false; // check if the woman married
		if ((mp[i][pro[c]] < mp[i][pro[i]]) && (wp[pro[c]][i] < wp[pro[c]][c])) return false; // Condition 2
        if ((mp[c][pro[i]] < mp[c][pro[c]]) && (wp[pro[i]][c] < wp[pro[i]][i])) return false; // Condition 3
	}
	/*Similar to 1D Queens, use a loop to check the array.
	  Inside the loop we chould check for 3 conditions
	  First condition checks is the same women is married to two different man *hint we need to check if two things are equal*
	  Second condition checks if (Man_i) and (Man_c's wife) both like each other more than their own spouse
	  Third condition checks if (Man_c) and (Man_i's wife) both like each other more than their own spouse

	  mp[i][j] tells you how much Man_i likes Woman_j. (0 = favorite; 2 = least favorite)
	  wp[i][j] tells you how much Woman_i likes Man_j.

	  mp[i][pro[i]] tells you how much Man_i likes his own wife.
	  mp[i][pro[c]] tells you how much Man_i likes Man_c's wife.
	  wp[pro[i]][i] tells you how much Man_i's wife likes Man_i.
	  wp[pro[i]][c] tells you how much Man_i's wife likes Man_c.
	  If mp[i][pro[c]] < mp[i][pro[i]], it means that Man_i likes Man_c's wife more than his own wife
	*/

	return true;//if we pass the loop, what do we return?
}

void print(int q[]) {
	static int solution = 0;
	cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
	for (int i=0; i<3; i++) {//Finish this print function such that you print the index (man) and value (woman) with a tab inbetween
		cout << i << "\t" << q[i] << endl;
	}
	cout << endl;
}

int main() {//Write the main function
	//The main function is the same as 8 cross. EXCEPT the array size is different.
	int q[3]={-1,-1,-1}; //initialize all position to -1;
	int c=0;

	while (c>=0) {
		q[c]++;
		if (q[c]==3){ // if out of range, backtrcking
			q[c]=-1; //reset
			c--;
		} else if (ok (q,c)){
			if (c==2) {
				print (q);
			}else {
				c++; // move to next column
				q[c]=-1; //reset
			}
		}
	}
	
	
	return 0;
}
