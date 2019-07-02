// Iterative C++ program to find modular 
// inverse using extended Euclid algorithm 
#include <iostream>

using namespace std; 
  
// Returns modulo inverse of a with respect 
// to m using extended Euclid Algorithm 
// Assumption: a and m are coprimes, i.e., 
// gcd(a, m) = 1 

int modInverse(int a, int m) ; 
  
// Driver program to test above function 

int main() 
{ 
    int num, mod;

    cout<<"num: ";
    cin>>num;
    cout<<"mod: ";
    cin>>mod;
  
    cout<<"\n\nInverso multiplicativo: "<<modInverse(num, mod); 
    return 0; 
} 


int modInverse(int a, int m) 
{ 
    int m0 = m; 
    int y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
        // q is quotient 
        int q = a / m; 
        int t = m; 
  
        // m is remainder now, process same as 
        // Euclid's algo 
        m = a % m, a = t; 
        t = y; 
  
        // Update y and x 
        y = x - q * y; 
        x = t; 
    } 
  
    // Make x positive 
    if (x < 0) 
       x += m0; 
  
    return x; 
}