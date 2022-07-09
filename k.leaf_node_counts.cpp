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


int getLeafNodeCount(TreeNode<int>* root) {
    //edge_case
    if(root==NULL){
        return 0;
    }

    //base
    if(root->children.size()==0){
        return 1;
    }
    //induction
    int cnt=0;
    for (int i = 0; i < root->children.size(); i++)
    {
        cnt+=getLeafNodeCount(root->children[i]);
    }
    return cnt; 
}