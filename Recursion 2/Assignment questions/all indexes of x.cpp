// All indexes of x

// Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in the output array (in increasing order).
// Do this recursively. Indexing in the array starts from 0.
// Hint:
// Try making a helper function with the required arguments and call the helper function from the allIndexes function.
// Input Format :
// Line 1 : An Integer N i.e. size of array
// Line 2 : N integers which are elements of the array, separated by spaces
// Line 3 : Integer x
// Output Format :
// Return all the indexes in the output array (in increasing order).
// Constraints :
// 1 <= N <= 10^3
// Sample Input :
// 5
// 9 8 10 8 8
// 8
// Sample Output :
// 1 3 4

// Code:

#include <bits/stdc++.h>
using namespace std;

int allIndexes(int input[], int size, int x, int output[])
{
    if (size == 0)
        return 0;
    int ans = allIndexes(input + 1, size - 1, x, output);

    // now if our 1st element is x, we first increase the output indexes by 1 and then shift them by 1 and add 0
    // at the 0th index in the output array

    if (input[0] == x)
    {
        int i;
        for (i = 0; i < ans; i++)
        {
            output[i]++;
        }
        for (i = ans - 1; i >= 0; i--)
        {
            output[i + 1] = output[i];
        }
        output[0] = 0;
        ans++;
    }
    else
    {
        int i;
        for (i = 0; i < ans; i++)
        {
            output[i]++;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int *input = new int[n];
    int *output = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int x;
    cin >> x;
    int size = allIndexes(input, n, x, output);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << " ";
    }
    delete[] input;
    delete[] output;
}

// Input:
// 6
// 1 4 3 4 5 4 
// 4
// Output:
// 1 3 5 