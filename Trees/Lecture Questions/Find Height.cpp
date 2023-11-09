// Code: Find Height
//
// Given a generic tree, find and return the height of given tree. The height of a tree is defined as the longest distace from root to any of the leaf node. Assume the height of the tree with a single node is 1.

// Input format :
// The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

// Output format :
// The first and only line of output prints the height of the given generic tree.

// Constraints:
// Time Limit: 1 sec

// Sample Input 1:
// 10 3 20 30 40 2 40 50 0 0 0 0
// Sample Output 1:
// 3

// Code:

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

int getHeight(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int height = 0;
    for (int i = 0; i < (int)root->children.size(); i++)
    {
        int childHeight = getHeight(root->children[i]);
        if (height < childHeight)
        {
            height = childHeight;
        }
    }
    return height + 1;
}

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        TreeNode<int> *frontNode = pendingNodes.front();
        pendingNodes.pop();

        int numChild;
        cin >> numChild;

        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *childNode = new TreeNode<int>(childData);
            frontNode->children.push_back(childNode);
            pendingNodes.push(childNode);
        }
    }

    return root;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    cout << getHeight(root);
}

// Output:
// 10 20 30 