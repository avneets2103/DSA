#include<iostream>
#include<queue>
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

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        return NULL;
    }
    root->left=removeLeafNodes(root->left);
    root->right=removeLeafNodes(root->right);
    return root;
}