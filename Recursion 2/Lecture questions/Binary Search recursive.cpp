// Binary Search (Recursive)

// Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.
// Return -1 if x is not present in the given array.
// Note : If given array size is even, take first mid.
// Input format :

// Line 1 : Array size

// Line 2 : Array elements (separated by space)

// Line 3 : x (element to be searched)

// Sample Input :
// 6
// 2 3 4 5 6 8 
// 5 
// Sample Output:
// 3 
// Hint : Use helper function to solve this question.

// Code:

#include <iostream>
using namespace std;

int binarySearchHelper(int input[], int si, int li, int ele) {
    if(si>li) return -1;
    int mid = (si+li)/2;
    if(input[mid]==ele) return mid;
    else if(input[mid]>ele) return binarySearchHelper(input, si, mid-1, ele);
    else return binarySearchHelper(input, mid+1, li, ele);
}

int binarySearch(int input[], int size, int element) {
    if(size==0) return -1;
    return binarySearchHelper(input, 0, size-1, element);
}

int main() {
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i=0; i<n; i++) {
        cin >> input[i];
    }
    int x;
    cin >> x;
    cout << binarySearch(input, n, x) << endl;
    delete [] input;
}

// Output:
// 6
// 1 2 3 4 5 6
// 5
// 4