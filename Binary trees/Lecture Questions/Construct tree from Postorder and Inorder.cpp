// Construct Tree from Postorder and Inorder

// For a given postorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root. Note: Assume that the Binary Tree contains only unique elements.

// Input Format:
// The first line of input contains an integer N, denoting the size of the array/list. It can also be said that N is the total number of nodes the binary tree would have. The second line of input contains N integers, all separated by a single space. It represents the Postorder-traversal of the binary tree. The third line of input contains N integers, all separated by a single space. It represents the inorder-traversal of the binary tree.

// Output Format:
// The given input tree will be printed in a level order fashion where each level will be printed on a new line. Elements on every level will be printed in a linear fashion. A single space will separate them.

// Constraints:
// 1 <= N <= 10^4
// Where N is the total number of nodes in the binary tree.
// Time Limit: 1 sec

// Sample Input 1:
// 7
// 4 5 2 6 7 3 1
// 4 2 5 1 6 3 7
// Sample Output 1:
// 1
// 2 3
// 4 5 6 7

// Sample Input 2:
// 6
// 2 9 3 6 10 5
// 2 6 3 9 5 10
// Sample Output 2:
// 5
// 6 10
// 2 3
// 9

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

BinaryTreeNode<int> *buildTreeHelper(int *postorder, int pstart, int pend, int *inorder, int instart, int inend)
{

    if (instart > inend || pstart > pend)
        return NULL;

    int rootValue = postorder[pend];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootValue);
    int rootIndex = -1;

    for (int i = instart; i <= inend; i++)
    {
        if (rootValue == inorder[i])
        {
            rootIndex = i;
            break;
        }
    }

    int noEleLT = rootIndex - instart;

    int postLStart = pstart;
    int postLEnd = pstart + noEleLT - 1;
    int inLStart = instart;
    int inLEnd = rootIndex - 1;
    int postRStart = postLEnd + 1;
    int postREnd = pend - 1;
    int inRStart = rootIndex + 1;
    int inREnd = inend;

    root->left = buildTreeHelper(postorder, postLStart, postLEnd, inorder, inLStart, inLEnd);
    root->right = buildTreeHelper(postorder, postRStart, postREnd, inorder, inRStart, inREnd);
    return root;
}

BinaryTreeNode<int> *buildTree(int *postorder, int postLength, int *inorder, int inLength)
{
    return (buildTreeHelper(postorder, 0, postLength - 1, inorder, 0, inLength - 1));
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

void printLevelATNewLine(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL)
        {
            if (q.empty())
            {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL)
        {
            q.push(first->left);
        }
        if (first->right != NULL)
        {
            q.push(first->right);
        }
    }
}

int main()
{
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++)
        cin >> post[i];
    for (int i = 0; i < size; i++)
        cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(post, size, in, size);
    printLevelATNewLine(root);
}
