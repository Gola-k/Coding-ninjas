// Preorder Binary Tree

// You are given a Binary Tree. Return the PreOrderTraversal of the given binary tree.
// Pre-order traversal is: Root LeftChild RightChild

/* 
Example:
        1
      /  \
     2    3
    / \  / \
   4  5  6  7
*/
// Pre-order traversal will be: 1 2 4 5 3 6 7

// Input Format:
// The only line conatins element in the level order form. The line consists of values of nodes separated by a single space. In case a node is null, we take -1 in its place.

// Output Format:
// Returning an array represnting the Pre-Order Traversal of the given binary tree.

// Constraints:
// 1 <= N <= 10^5
// Where N is the total number of nodes in the binary tree.
// Time Limit: 1 sec

// Sample Input 1:
// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
// Sample Output 1:
// 5 6 2 3 9 10

// Sample Input 2:
// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
// Sample Output 2:
// 1 2 4 5 3 6 7

// Code:

#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <stack>
using namespace std;

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

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

vector<int> preOrder(TreeNode<int> *root)
{
    vector<int> path;
    stack<TreeNode<int> *> s;

    s.push(root);

    while (!s.empty())
    {
        TreeNode<int> *currentNode = s.top();
        s.pop();
        path.push_back(currentNode->data);
        if (currentNode->right != NULL)
            s.push(currentNode->right);
        if (currentNode->left != NULL)
            s.push(currentNode->left);
    }

    return path;
}

class Runner
{
    int t;
    vector<TreeNode<int> *> allTrees;

    TreeNode<int> *takeTreeInput()
    {

        int rootData;
        cin >> rootData;

        if (rootData == -1)
        {
            return NULL;
        }

        TreeNode<int> *root = new TreeNode<int>(rootData);

        queue<TreeNode<int> *> q;
        q.push(root);

        while (q.empty() == false)
        {
            TreeNode<int> *currentNode = q.front();
            q.pop();
            int leftChild, rightChild;

            cin >> leftChild;

            if (leftChild != -1)
            {
                TreeNode<int> *leftNode = new TreeNode<int>(leftChild);

                currentNode->left = leftNode;
                q.push(leftNode);
            }

            cin >> rightChild;

            if (rightChild != -1)
            {
                TreeNode<int> *rightNode = new TreeNode<int>(rightChild);

                currentNode->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }

    TreeNode<int> *copyTree(TreeNode<int> *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        TreeNode<int> *copyRoot = new TreeNode<int>(root->data);
        copyRoot->left = copyTree(root->left);
        copyRoot->right = copyTree(root->right);
        return copyRoot;
    }

public:
    void takeInput()
    {
        t = 1;
        allTrees.resize(t);

        for (int i = 0; i < t; i++)
        {
            allTrees[i] = takeTreeInput();
        }
    }

    void execute()
    {
        for (int i = 0; i < t; i++)
        {
            TreeNode<int> *copyRoot = copyTree(allTrees[i]);

            vector<int> ans = preOrder(copyRoot);

            delete copyRoot;
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {

            vector<int> ans = preOrder(allTrees[i]);
            for (auto i : ans)
                cout << i << " ";
            cout << '\n';
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