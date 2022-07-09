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

int Height(TreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    //induction
    int max_height=0;
    for (int i = 0; i < root->children.size(); i++)
    {
        if(max_height<Height(root->children[i])){
            max_height=Height(root->children[i]);
        }
    }
    return max_height+1;
}

int getDepth(TreeNode<int>* root){
    if(root==NULL){
        return 0; 
    }
    int max_depth=0;
    for(int i =0; i<root->children.size(); i++){
        if(max_depth<getDepth(root->children[i])){
            max_depth=getDepth(root->children[i]);
        }
    }
    return max_depth;
}