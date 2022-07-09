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

int height(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right)); 
}

bool isBalanced(BinaryTreeNode<int> *root) {
    if(root==NULL){
        return true;
    }
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    bool height_cond=((height(root->left)-height(root->right)<=1 & height(root->left)-height(root->right)>=-1));
    return height_cond & isBalanced(root->left) & isBalanced(root->right);
}