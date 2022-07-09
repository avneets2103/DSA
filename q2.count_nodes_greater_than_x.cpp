// Given a tree and an integer x, find and return the number of nodes which contains data greater than x.
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

int getLargeNodeCount(TreeNode<int>* root, int x) {
    if(root==NULL){
        return 0;
    }
    int count = 0;
    if(root->data>x){
        count += 1;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        count += getLargeNodeCount(root->children[i],x);
    }
    return count;
}