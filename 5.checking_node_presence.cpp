#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<int> *left;
    BinaryTreeNode<int> *right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    bool ans = false;
    if (root == NULL)
    {
        return false;
    }
    if (root->data == x)
    {
        ans = true;
        return ans;
    }
    ans = isNodePresent(root->left, x) | isNodePresent(root->right, x);
    return ans;
}