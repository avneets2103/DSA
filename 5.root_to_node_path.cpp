//root to node path in binary tree

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class BinaryTreeNode{
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

bool searchInBST(BinaryTreeNode<int>* root, int k){
    if(root==NULL){
        return false;
    }
    if(root->data==k){
        return true;
    }
    if(root->data>k){
        return searchInBST(root->left,k);
    }
    if(root->data<k){
        return searchInBST(root->right,k);
    }
}

vector<int>* getPath(BinaryTreeNode<int> *root , int data){
    if(!searchInBST(root,data)){
        return NULL;
    }
    if(root==NULL){
        vector<int>* path;
        return path;
    }

    if(root->data==data){
        vector<int>* path = new vector<int>();
        path->push_back(root->data);
        return path;
    }
    if(searchInBST(root->left,data)){
        vector<int>* left_path=getPath(root->left,data);
        left_path->push_back(root->data);
        return left_path;
    }
    if(searchInBST(root->right,data)){
        vector<int>* right_path=getPath(root->right,data);
        right_path->push_back(root->data);
        return right_path;
    }
}
