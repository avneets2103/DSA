// Given a generic tree and an integer x, check if x is present in the given tree or not. Return true if x is present, return false otherwise.

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

bool isPresent(TreeNode<int>* root, int x) {
    bool truth = false;
    if(root->data==x){
        return true;
    }  
    for (int i = 0; i < root->children.size(); i++)
    {
        if(isPresent(root->children[i],x)){
            truth=true;
        }
    }
    return truth;
}