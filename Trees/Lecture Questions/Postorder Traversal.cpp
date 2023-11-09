// Code: Postorder Traversal

// Given a generic tree, print the post-order traversal of given tree. The post-order traversal is : visit child nodes first and then root node.

/*
       10
     /  | \
    20 30 40
    / \
   40  50
*/

// Post-order traversal is : 40 50 20 30 40 10

// Input format :
// The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

// Output Format :
// The first and only line of output prints the post-order traversal. The elements printed in the post-order traversal are separated by a single space.

// Constraints:
// Time Limit: 1 sec

// Sample Input 1:
// 10 3 20 30 40 2 400 50 0 0 0 0
// Sample Output 1:
// 400 50 20 30 40 10
// Explanation:
// For 10, total 3 children are there : 20 30 40
// For 20, total 2 children are there : 400 50
// So the output will be : 400 50 20 30 40 10

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

void postOrder(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    for (int i = 0; i < (int)root->children.size(); i++)
    {
        postOrder(root->children[i]);
    }
    cout << root->data << " ";
}

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    postOrder(root);
}
