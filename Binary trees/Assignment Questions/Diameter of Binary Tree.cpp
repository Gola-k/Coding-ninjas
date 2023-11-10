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

// Helper function for calculating diameter of binary tree
pair<int, int> heightDiameterHelper(BinaryTreeNode<int> *root)
{

    // if the given tree is empty or we reach end of root
    if (root == NULL)
    {

        // this pair will going to store both height and diameter
        pair<int, int> p;
        p.first = 0;  // height
        p.second = 0; // diameter
        return p;
    }

    // we made two recursive calls for left subtree and right subtree
    pair<int, int> leftAns = heightDiameterHelper(root->left);
    pair<int, int> rightAns = heightDiameterHelper(root->right);
    int ld = leftAns.second;  // left diameter
    int lh = leftAns.first;   // left height
    int rd = rightAns.second; // right diameter
    int rh = rightAns.first;  // right height

    // height will be 1 plus maximum of left height & right height
    int height = 1 + max(lh, rh);

    // diameter will be max among left diameter, right diameter and sum of left height plus right height
    int diameter = max(lh + rh, max(ld, rd));

    // then making a pair and storing the height and diameter in it
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

// function for calculating diameter of binary tree
int diameter(BinaryTreeNode<int> *root)
{
    return heightDiameterHelper(root).second;
}

// taking input level-wise
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
    cout << diameter(root);
}