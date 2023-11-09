// Print Level wise

// For a given binary tree of type integer, print the complete information of every node, when traversed in a level-order fashion.
// To print the information of a node with data D, you need to follow the exact format :
// D:L:X,R:Y
// where D is the data of a node present in the binary tree. X and Y are the values of the left(L) and right(R) child of the node. Print -1 if the child doesn't exist.

// Example:
/*
        1 (root)
       / \
      2   3
     /   / \
    4   5   6
    |
    7
For the above depicted tree, when printed in a level-order fashion, the output would look like this:
1:L:2,R:3
2:L:4,R:-1
3:L:5,R:6
4:L:7,R:-1
5:L:-1,R:-1
6:L:-1,R:-1
7:L:-1,R:-1
*/

// Input format:
// The first and the only line of input will contain the nodes data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
// Output Format:
// Information of all the nodes in the Binary Tree will be printed on a different line where each node will follow a format of D:L:X,R:Y, without any spaces in between.
// Constraints:
// 1 <= N <= 10^5
// Where N is the total number of nodes in the binary tree.
// Time Limit: 1 sec

// Sample Input 1:
// 1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1
// Sample Output 1:
// 1:L:2,R:3
// 2:L:4,R:5
// 3:L:-1,R:6
// 4:L:-1,R:-1
// 5:L:-1,R:-1
// 6:L:-1,R:-1

// Sample Input 2:
// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
// Sample Output 2:
// 5:L:6,R:10  
// 6:L:2,R:3   
// 10:L:-1,R:-1
// 2:L:-1,R:-1 
// 3:L:-1,R:9  
// 9:L:-1,R:-1 

// Code:

#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild = currentNode->left == NULL ? -1 : currentNode->left->data;
        int rightChild = currentNode->right == NULL ? -1 : currentNode->right->data;

        cout << currentNode->data << ":L:" << leftChild << ",R:" << rightChild << endl;

        if (leftChild != -1)
        {
            q.push(currentNode->left);
        }

        if (rightChild != -1)
        {
            q.push(currentNode->right);
        }
    }
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;

    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    printLevelWise(root);
}