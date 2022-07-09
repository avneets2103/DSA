// Given a generic tree and an integer n. Find and return the node with next larger element in the tree i.e. find a node with value just greater than n.
// Note: Return NULL if no node is present with the value greater than n.

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

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    TreeNode<int>* min_more_than_x=NULL;
    if(root->data>x){
        min_more_than_x=root;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        if(min_more_than_x==NULL){
            min_more_than_x=getNextLargerElement(root->children[i],x);
            continue;
        }
        if(getNextLargerElement(root->children[i],x)==NULL){
            continue;
        }
        if(min_more_than_x->data > getNextLargerElement(root->children[i],x)->data){
            min_more_than_x=getNextLargerElement(root->children[i],x);
        }
    }
    return min_more_than_x;
}