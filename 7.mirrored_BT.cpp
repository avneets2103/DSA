#include<iostream>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<int>* left;
    BinaryTreeNode<int>* right;
    BinaryTreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

void mirrorBinaryTree(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    swap(root->left,root->right);
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}