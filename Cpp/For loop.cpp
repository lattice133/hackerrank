#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
    
    int lowerbound, upperbound; 
    int n;
    
    cin >> lowerbound >> upperbound; 
    
	for(n = lowerbound; n <= upperbound; n++){
            
        if (1 == n) cout << "one" << endl;
        else if (2 == n) cout << "two" << endl;
        else if (3 == n) cout << "three" << endl;
        else if (4 == n) cout << "four" << endl;
        else if (5 == n) cout << "five" << endl;
        else if (6 == n) cout << "six" << endl;
        else if (7 == n) cout << "seven" << endl;
        else if (8 == n) cout << "eight" << endl;
        else if (9 == n) cout << "nine" << endl;
        else if ((n > 9) & (0 == n%2)) cout << "even" << endl;
        else if ((n > 9) & (1 == n%2)) cout << "odd" << endl;
         
    }
    
    
    return 0;
}


