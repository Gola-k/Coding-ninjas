// Delete node

// You have been given a linked list of integers. Your task is to write a function that deletes a node from a given position, 'POS'.
// Note :
// Assume that the Indexing for the linked list always starts from 0.

// If the position is greater than or equal to the length of the linked list, you should return the same linked list without any change.
// Illustration :
// The following images depict how the deletion has been performed.
// Image-I :
// Alt txt

// Image-II :
// Alt txt

// Input format :
// The first line contains the elements of the linked list separated by a single space. 
// The second line contains the integer value of 'POS'. It denotes the position in the linked list from where the node has to be deleted.
//  Remember/Consider :
// While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
// Output format :
// Print the resulting linked list of integers in a row, separated by a single space.
// Note:
// You are not required to print the output, it has already been taken care of. Just implement the function. 
// Sample Input 1 :
// 3 4 5 2 6 1 9 -1
// 3
// Sample Output 1 :
// 3 4 5 6 1 9
// Explanation of Sample Output 1 :
// The data in the node with index 3 is 2 which has been removed.
// Sample Input 2 :
// 3 4 5 2 6 1 9 -1
// 0
// Sample Output 2 :
// 4 5 2 6 1 9
// Constraints :
// 0 <= N <= 10^5
// POS >= 0

// Time Limit: 1sec
// Expected Complexity :
// Time Complexity  : O(N)
// Space Complexity  : O(1)

// Code:

#include <bits/stdc++.h>
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

Node *deleteNode(Node *head, int pos)
{
    if(head == NULL) return head;

    if(pos == 0) {
        Node *temp = head;
        temp = temp->next;
        delete head;
        return temp;
    }

    Node *temp = head;
    int count = 0;
    while(count < pos - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if(temp == NULL || temp->next == NULL) return head;

    Node *NodeAtPos = temp->next;
    temp->next = NodeAtPos->next;
    delete NodeAtPos;
    return head;
}

class Runner
{
    int pos;
    Node *head = NULL;

public:
    void takeInput()
    {
        int data;
        cin >> data;
        Node *tail = NULL;
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
        cin >> pos;
    }
    Node *copyll(Node *chead)
    {
        if (chead == NULL)
            return NULL;
        Node *nhead = NULL;

        Node *tail = NULL;
        while (chead != NULL)
        {
            Node *newNode = new Node(chead->data);
            if (nhead == NULL)
            {
                nhead = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            chead = chead->next;
        }
        return nhead;
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
    void execute()
    {
        Node *copyhead = copyll(head);
        copyhead = deleteNode(copyhead, pos);
        while (copyhead != NULL)
        {
            Node *temp = copyhead;
            copyhead = copyhead->next;
            delete temp;
        }
    }
    void executeAndPrintOutput()
    {
        Node *copyhead = copyll(head);
        copyhead = deleteNode(copyhead, pos);
        print(copyhead);
        while (copyhead != NULL)
        {
            Node *temp = copyhead;
            copyhead = copyhead->next;
            delete temp;
        }
    }
};

int main()
{
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}

// Input:
// 3 4 5 2 6 1 9 -1
// 3
// Output:
// 3 4 5 6 1 9