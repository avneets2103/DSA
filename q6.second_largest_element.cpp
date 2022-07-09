// Given a generic tree, find and return the node with second largest value in given tree.
// Note: Return NULL if no node with required value is present.
#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode*> children;
    TreeNode(int data){
        this->data=data;
    }
};

TreeNode<int>* getNextsmallerElement(TreeNode<int>* root, int x) {
    TreeNode<int>* min_more_than_x=NULL;
    if(root->data<x){
        min_more_than_x=root;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        if(min_more_than_x==NULL){
            min_more_than_x=getNextsmallerElement(root->children[i],x);
            continue;
        }
        if(getNextsmallerElement(root->children[i],x)==NULL){
            continue;
        }
        if(min_more_than_x->data < getNextsmallerElement(root->children[i],x)->data){
            min_more_than_x=getNextsmallerElement(root->children[i],x);
        }
    }
    return min_more_than_x;
}


TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    TreeNode<int>* max_node = root;
    for(int i=0; i<root->children.size(); i++){
        if(max_node->data < maxDataNode(root->children[i])->data){
            max_node = maxDataNode(root->children[i]);
        }
    }
    return max_node;
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    TreeNode<int>* largest = maxDataNode(root);
    int x = largest->data;
    return getNextsmallerElement(root,x); 
}