// Even after Odd Linked List

// For a given singly linked list of integers, arrange the nodes such that all the even number nodes are placed after the all odd number nodes. The relative order of the odd and even terms should remain unchanged.
// Note :
// 1. No need to print the linked list, it has already been taken care. Only return the new head to the list.
// 2. Don't create a new linked list.
// 3.  Just change the data, instead rearrange the provided list.

// Input format:
// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
// The first line of each test case or query contains the elements of the singly linked list separated by a single space. 
//  Remember/Consider :
// While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

// Output format:
// For each test case/query, print the elements of the updated singly linked list.
// Output for every test case will be printed in a seperate line.

// Constraints :
// 1 <= t <= 10^2
// 0 <= M <= 10^5
// Where M is the size of the singly linked list.
// Time Limit: 1sec

// Sample Input 1 :
// 1
// 1 4 5 2 -1
// Sample Output 1 :
// 1 5 4 2 
// Sample Input 2 :
// 2
// 1 11 3 6 8 0 9 -1
// 10 20 30 40 -1
// Sample Output 2 :
// 1 11 3 9 6 8 0
// 10 20 30 40

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

Node *evenAfterOdd(Node *head)
{
    Node *ohead = NULL;
    Node *otail = NULL;
    Node *ehead = NULL;
    Node *etail = NULL;

    while (head != NULL)
    {

        if (head->data % 2 == 0 && ehead == NULL)
        {
            ehead = head;
            etail = head;
        }
        else if (head->data % 2 != 0 && ohead == NULL)
        {
            ohead = head;
            otail = head;
        }
        else if (head->data % 2 == 0)
        {
            etail->next = head;
            etail = head;
        }
        else if (head->data % 2 != 0)
        {
            otail->next = head;
            otail = head;
        }

        head = head->next;
    }

    if (ohead == NULL)
        return ehead;
    else if (ehead == NULL)
        return ohead;

    otail->next = ehead;
    etail->next = NULL;

    return ohead;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        head = evenAfterOdd(head);
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
// 1 4 5 2 -1
// 1 5 4 2