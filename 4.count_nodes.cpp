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

int count_nodes(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return 1+count_nodes(root->left)+count_nodes(root->right);
}