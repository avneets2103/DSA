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

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
    if(root->left==NULL && root->right==NULL){
        pair<int, int> p;
        p.first=root->data;
        p.second=root->data;
        return p;
    }
    if(root->right==NULL){
        pair<int, int> p;
        p.first=min(root->data,root->left->data);
        p.second=max(root->data,root->left->data);
        return p;
    }
    if(root->left==NULL){
        pair<int, int> p;
        p.first=min(root->data,root->right->data);
        p.second=max(root->data,root->right->data);
        return p;
    }
    int max_data=max(root->data,max(getMinAndMax(root->left).second,getMinAndMax(root->right).second));
    int min_data=min(root->data,min(getMinAndMax(root->left).first,getMinAndMax(root->right).first));
    pair<int,int> p;
    p.first=min_data;
    p.second=max_data;
    return p;
}