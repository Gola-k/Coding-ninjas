// Delete every N nodes

// You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. Continue the same until the end of the linked list. Indexing starts from 1.
// To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.
// Note :
// No need to print the list, it has already been taken care. Only return the new head to the list. You can return null in case where all nodes will be deleted.

// Input format :
// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
// The first line of each test case or query contains the elements of the singly linked list separated by a single space.
// The second line of input contains two integer values 'M,' and 'N,' respectively. A single space will separate them.
//  Remember/Consider :
// While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

// Output format :
// For each test case/query, print the elements of the updated singly linked list.
// Output for every test case will be printed in a seperate line.

// Constraints :
// 1 <= t <= 10^2
// 0 <= P <= 10^5
// Where P is the size of the singly linked list.
// 0 <= M <= 10^5
// 0 <= N <= 10^5 
// Time Limit: 1sec

// Sample Input 1 :
// 1
// 1 2 3 4 5 6 7 8 -1
// 2 2
// Sample Output 1 :
// 1 2 5 6
// Sample Input 2 :
// 2
// 10 20 30 40 50 60 -1
// 0 1
// 1 2 3 4 5 6 7 8 -1
// 2 3
// Sample Output 2 :
// 1 2 6 7
// Explanation of Sample Input 2 :
// For the first query, we delete one node after every zero elements hence removing all the items of the list. Therefore, nothing got printed.
// For the second query, we delete three nodes after every two nodes, resulting in the final list, 1 -> 2 -> 6 -> 7.

// Code:

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        cin >> data;
    }
    return head;
}

Node *deleteNodes(Node *head, int count)
{
    while (count-- && head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    return head;
}

Node *skipMdeleteN(Node *head, int M, int N)
{
    if (head == NULL || N == 0)
        return head;

    if (M == 0)
        return deleteNodes(head, -1);

    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        // Skip M nodes
        for (int i = 0; i < M && curr != NULL; i++)
        {
            prev = curr;
            curr = curr->next;
        }

        // Delete N nodes
        Node *nextNode = deleteNodes(curr, N);
        prev->next = nextNode;

        // Move prev to the last node of the deleted segment
        prev = curr;
        curr = nextNode;
    }

    return head;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        int m, n;
        cin >> m >> n;
        head = skipMdeleteN(head, m, n);
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }

    return 0;
}

// Output:
// 1 
// 1 2 3 4 5 6 7 8 -1
// 2 2
// 1 2 5 6 