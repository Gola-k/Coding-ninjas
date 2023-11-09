// Second largest element in Tree

// Given a generic tree find and return the node with second largest value in given tree. Note: Return NULL if no node with required value is present.

// Input format :
// The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space. Also value of data at each level is distinct.

// Output format:
// The first and only line of output contains data of the node with second largest data.

// Constraints:
// Time Limit: 1 sec

// Sample Input 1:
// 10 3 20 30 40 2 40 50 0 0 0 0
// Sample Output 1:
// 40

// Code:

#include <iostream>
#include <queue>
#include <vector>
#include <climits>
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

void findSecondLargestNode(TreeNode<int> *root, TreeNode<int> *&first, TreeNode<int> *&second)
{
    if (root == nullptr)
        return;

    // Update first and second largest nodes
    if (root->data > first->data)
    {
        second = first;
        first = root;
    }
    else if (root->data < first->data && (second == nullptr || root->data > second->data))
    {
        second = root;
    }

    for (TreeNode<int> *child : root->children)
    {
        findSecondLargestNode(child, first, second);
    }
}

TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    TreeNode<int> *firstLargest = root;
    TreeNode<int> *secondLargest = nullptr;

    findSecondLargestNode(root, firstLargest, secondLargest);
    return secondLargest;
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

    TreeNode<int> *ans = getSecondLargestNode(root);

    if (ans != NULL)
    {
        cout << ans->data;
    }
    else
    {
        cout << INT_MIN;
    }
}