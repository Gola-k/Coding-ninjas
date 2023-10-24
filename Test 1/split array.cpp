// Split Array

// Given an integer array A of size N, check if the input array can be divided in two groups G1 and G2 with following properties-
// - Sum of both group elements are equal
// - Group 1: All elements in the input, which are divisible by 5 
// - Group 2: All elements in the input, which are divisible by 3 (but not divisible by 5). 
// - Elements which are neither divisible by 5 nor by 3, can be put in either group G1 or G2 to satisfy the equal sum property. 
// Group 1 and Group 2 are allowed to be unordered and all the elements in the Array A must belong to only one of the groups.
// Return true, if array can be split according to the above rules, else return false.
// Note: You will get marks only if all the test cases are passed.

// Input Format :
// Line 1 : Integer N (size of array)
// Line 2 : Array A elements (separated by space)

// Output Format :
// true or false

// Constraints :
// 1 <= N <= 50

// Sample Input 1 :
// 2
// 1 2
// Sample Output 1 :
// false
// Sample Input 2 :
// 3
// 1 4 3
// Sample Output 2 :
// true

// Code:

#include <bits/stdc++.h>
using namespace std;

// Recursive function that returns true if the array
// can be divided into two sub-arrays
// satisfying the given condition
bool helper(int *arr, int n, int start, int lsum, int rsum)
{

    // If reached the end
    if (start == n)
        return lsum == rsum;

    // If divisible by 5 then add to the left sum
    if (arr[start] % 5 == 0)
        lsum += arr[start];

    // If divisible by 3 but not by 5
    // then add to the right sum
    else if (arr[start] % 3 == 0)
        rsum += arr[start];

    // Else it can be added to any of the sub-arrays
    else

        // Try adding in both the sub-arrays (one by one)
        // and check whether the condition satisfies
        return helper(arr, n, start + 1, lsum + arr[start], rsum) || helper(arr, n, start + 1, lsum, rsum + arr[start]);

    // For cases when element is multiple of 3 or 5.
    return helper(arr, n, start + 1, lsum, rsum);
}

// Function to start the recursive calls
bool splitArray(int *arr, int n)
{
    // Initially start, lsum and rsum will all be 0
    return helper(arr, n, 0, 0, 0);
}

// Driver code
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (splitArray(arr, n))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    delete[] arr;
}

// Input:
// 5
// 1 2 3 4 5
// Output:
// false