// kReverse

// Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
//  'k' is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of 'k,' then left-out nodes, in the end, should be reversed as well.
// Example :
// Given this linked list: 1 -> 2 -> 3 -> 4 -> 5
// For k = 2, you should return: 2 -> 1 -> 4 -> 3 -> 5
// For k = 3, you should return: 3 -> 2 -> 1 -> 5 -> 4
//  Note :
// No need to print the list, it has already been taken care. Only return the new head to the list.

//  Input format :
// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
// The first line of each test case or query contains the elements of the singly linked list separated by a single space.
// The second line of input contains a single integer depicting the value of 'k'.
//  Remember/Consider :
// While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

// Output format :
// For each test case/query, print the elements of the updated singly linked list.
// Output for every test case will be printed in a separate line.

// Constraints :
// 1 <= t <= 10^2
// 0 <= M <= 10^5
// Where M is the size of the singly linked list.
// 0 <= k <= M
// Time Limit:  1sec

// Sample Input 1 :
// 1
// 1 2 3 4 5 6 7 8 9 10 -1
// 4
// Sample Output 1 :
// 4 3 2 1 8 7 6 5 10 9
// Sample Input 2 :
// 2
// 1 2 3 4 5 -1
// 0
// 10 20 30 40 -1
// 4
// Sample Output 2 :
// 1 2 3 4 5 
// 40 30 20 10 

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

Node *kReverse(Node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    Node *current = head;
    Node *next = NULL;
    Node *prev = NULL;
    int count = 0;
    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if (next != NULL)
    {
        head->next = kReverse(next, k);
    }
    return prev;
}

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        int k;
        cin >> k;
        head = kReverse(head, k);
        print(head);
    }

    return 0;
}

// Output:
// 1
// 1 2 3 4 5 6 7 8 9 -1
// 3
// 3 2 1 6 5 4 9 8 7


// Approach 2:

// class Pair
// {
// public:
//     Node *head;
//     Node *tail;
//     Pair()
//     {
//         this->head = NULL;
//         this->tail = NULL;
//     }
// };

// Pair reverseLinkedListRec(Node *head, Node *tail)
// {
//     if (head == NULL || head->next == NULL)
//     {
//         Pair p;
//         p.head = head;
//         p.tail = head;
//         return p;
//     }

//     Pair smallHead = reverseLinkedListRec(head->next, tail);
//     head->next->next = head;
//     head->next = NULL;

//     Pair p;
//     p.head = smallHead.head;
//     p.tail = head;
//     return p;
// }

// Node *kReverse(Node *head, int k)
// {
//     if (head == NULL || k == 1 || k == 0)
//         return head;

//     Node *newHead = head;
//     Node *newTail = head;

//     int i = 1;
//     while (i < k && newTail != NULL && newTail->next != NULL)
//     {
//         newTail = newTail->next;
//         i++;
//     }

//     Node *nxtHead = NULL;
//     if (newTail->next != NULL)
//     {
//         nxtHead = newTail->next;
//         newTail->next = NULL;
//     }

//     Pair reversedPart = reverseLinkedListRec(newHead, newTail);

//     Node *nxtReversedLlHead = kReverse(nxtHead, k);

//     reversedPart.tail->next = nxtReversedLlHead;

//     return reversedPart.head;
// }
