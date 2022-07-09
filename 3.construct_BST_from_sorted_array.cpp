#include <iostream>
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

BinaryTreeNode<int>* constructTreeh(int* input, int si, int ei){
    if(si>ei){
        return NULL;
    }
    int mid = (si+ei)/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(input[mid]);
    BinaryTreeNode<int>* left = constructTreeh(input,si,mid-1);
    BinaryTreeNode<int>* right = constructTreeh(input,mid+1,ei);
    root->left=left;
    root->right=right;
    return root; 
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
    return constructTreeh(input,0,n-1);
}