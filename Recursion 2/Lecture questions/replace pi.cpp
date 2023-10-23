// Replace Pi

// Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
// Constraints :
// 1 <= |S| <= 50
// where |S| represents the length of string S. 
// Sample Input 1 :
// xpix
// Sample Output :
// x3.14x
// Sample Input 2 :
// pipi
// Sample Output :
// 3.143.14
// Sample Input 3 :
// pip
// Sample Output :
// 3.14p
// Constraints:-
// 1<=|S|<=50

// Code:

#include <bits/stdc++.h>
using namespace std;

void replacePi(char input[])
{
    // Base case: If the string is empty or has only one character, no replacements needed
    if (input[0] == '\0' || input[1] == '\0')
    {
        return;
    }

    // Recursive case:
    // If the first two characters are 'p' and 'i', replace them with "3.14"
    if (input[0] == 'p' && input[1] == 'i')
    {
        // Shift the remaining characters to the right
        for (int i = strlen(input); i >= 2; i--)
        {
            input[i + 2] = input[i];
        }

        // Replace 'p' and 'i' with '3', '.', '1', and '4'
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';

        // Recursively call replacePi on the remaining string (excluding the replaced portion)
        replacePi(input + 4);
    }
    else
    {
        // If the first two characters are not 'p' and 'i', move to the next character
        replacePi(input + 1);
    }
}

int main()
{
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}

// Output:
// xpix
// x3.14x