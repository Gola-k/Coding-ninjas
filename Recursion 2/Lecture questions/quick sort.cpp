// Quick Sort

// Given the 'start' and the 'end'' positions of the array 'input'. Your task is to sort the elements between 'start' and 'end' using quick sort.

// Note :
// Make changes in the input array itself.
// Input format :
// Line 1 : Integer N i.e. Array size
// Line 2 : Array elements (separated by space)
// Output format :
// Array elements in increasing order (separated by space)
// Sample Input 1 :
// 6 
// 2 6 8 5 4 3
// Sample Output 1 :
// 2 3 4 5 6 8
// Sample Input 2 :
// 5
// 1 2 3 5 7
// Sample Output 2 :
// 1 2 3 5 7 
// Constraints :
// 1 <= N <= 10^3
// 0 <= input[i] <= 10^9

#include <iostream>
using namespace std;

void swap(int input[], int a, int b)
{
    int temp = input[a];
    input[a] = input[b];
    input[b] = temp;
}

int partitionArray(int input[], int si, int ei)
{
    // finding the number of elements smaller than input[si]
    int count = 0;
    for (int i = si + 1; i <= ei; i++)
    {
        if (input[i] < input[si])
            count++;
    }

    // swap the [si] element with the position [si+count]
    swap(input, si, si + count);

    // now swap those element which are on the wrong side
    int i = si, j = ei, k = si + count;
    while (i < k && j > k)
    {
        if (input[i] < input[k])
            i++;
        else if (input[j] > input[k])
            j--;
        else
            swap(input, i, j);
    }

    // return the pivot position of the 1st element of the array
    return k;
}

void quickSort(int input[], int start, int end)
{
    if (start >= end)
        return;
    int c = partitionArray(input, start, end);
    quickSort(input, start, c - 1);
    quickSort(input, c + 1, end);
}

int main()
{
    int n;
    cin >> n;
    int *input = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    quickSort(input, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
    delete[] input;
}

// Output:
// 6
// 6 2 4 3 5 1
// 1 2 3 4 5 6