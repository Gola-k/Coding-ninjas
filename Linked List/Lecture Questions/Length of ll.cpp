#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

int length(Node *head)
{
    Node *temp = head;
    int length = 0;

    if (temp == NULL)
        return 0;

    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }

    return length;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = NULL;
        Node *tail = NULL;

        int data;
        cin >> data;

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

        cout << length(head) << endl;
    }

    return 0;
}

// Input:
// 1
// 1 2 3 4 5 -1
// Output:
// 5