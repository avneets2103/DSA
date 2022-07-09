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
    int left_height=height(root->left);
    int right_height=height(root->right);
    return 1 + max(left_height,right_height);
}

int main(){return 0;}
