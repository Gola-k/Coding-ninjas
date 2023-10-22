// Geometric Sum

// Given k, find the geometric sum i.e.
// 1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 
// using recursion.
// Input format :
// Integer k
// Output format :
// Geometric sum (upto 5 decimal places)
// Constraints :
// 0 <= k <= 1000
// Sample Input 1 :
// 3
// Sample Output 1 :
// 1.87500
// Sample Input 2 :
// 4
// Sample Output 2 :
// 1.93750
// Explanation for Sample Input 1:
// 1+ 1/(2^1) + 1/(2^2) + 1/(2^3) = 1.87500

// Code:

#include <iostream>
using namespace std;

double power(double x, double n) {
    if(n==0) return 1;
    return x*power(x, n-1);
}

double geometricSum(int k) {
    if(k==0) return 1;
    return 1/power(2, k) + geometricSum(k-1);
}

int main() {
    int k;
    cin >> k;
    cout << geometricSum(k) << endl;
    return 0;
}

// Output:
// 3
// 1.875