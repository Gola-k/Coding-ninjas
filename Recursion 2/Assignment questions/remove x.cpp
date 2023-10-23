// Remove X

// Given a string, compute recursively a new string where all 'x' chars have been removed.
// Input format :
// String S
// Output format :
// Modified String
// Constraints :
// 1 <= |S| <= 10^3
// where |S| represents the length of string S. 
// Sample Input 1 :
// xaxb
// Sample Output 1:
// ab
// Sample Input 2 :
// abc
// Sample Output 2:
// abc
// Sample Input 3 :
// xx
// Sample Output 3:

// Code:

#include <bits/stdc++.h>
using namespace std;

void removeX(char input[])
{
    if (input[0] == '\0')
        return;
    if (input[0] == 'x')
    {
        size_t i = 0;
        for (; i < strlen(input) - 1; i++)
        {
            input[i] = input[i + 1];
        }
        input[i] = '\0';
        removeX(input);
    } else {
        removeX(input+1);
    }

}

int main() {
    char input[100];
    cin >> input;
    removeX(input);
    cout << input << endl;
}

// Output:
// xaxb
// ab