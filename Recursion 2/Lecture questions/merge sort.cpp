// Merge Sort

// You are given the starting 'l' and the ending 'r' positions of the array 'ARR'.
// You must sort the elements between 'l' and 'r'.
// Note:
// Change in the input array itself. So no need to return or print anything.
// Example:
// Input: ‘N’ = 7,
// 'ARR' = [2, 13, 4, 1, 3, 6, 28]

// Output: [1 2 3 4 6 13 28]

// Explanation: After applying 'merge sort' on the input array, the output is [1 2 3 4 6 13 28].
// Input format :
// The first line contains an integer <em>**'N'**</em> representing the size of the array/list.
// The second line contains 'N' single space-separated integers representing the elements in the array/list.
// Output format :
// You don't need to return anything. In the output, you will see the array after you do the modification.
// Sample Input 1:
// 7
// 2 13 4 1 3 6 28
// Sample Output 1:
// 1 2 3 4 6 13 28
// Explanation of Sample Output 1:
// After applying 'merge sort' on the input array, the output is [1 2 3 4 6 13 28].
// Sample Input 2:
// 5
// 9 3 6 2 0
// Sample Output 2:
// 0 2 3 6 9
// Explanation of Sample Output 2:
// After applying 'merge sort' on the input array, the output is [0 2 3 6 9].
// Constraints :
// 1 <= N <= 10^3
// 0 <= ARR[i] <= 10^9

// Code:

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int l, int r)
{
    int mid = (l + r) / 2;
    int i = l;
    int j = mid + 1;
    int k = 0;
    int *arr1 = new int[r - l + 1];
    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            arr1[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            arr1[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        arr1[k] = arr[i];
        k++;
        i++;
    }
    while (j <= r)
    {
        arr1[k] = arr[j];
        k++;
        j++;
    }
    int t = 0;
    while (t < k)
    {
        arr[l + t] = arr1[t];
        t++;
    }
    delete[] arr1;
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, r);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}

// Output:
// 7
// 2 13 4 1 3 6 28
// 1 2 3 4 6 13 28
