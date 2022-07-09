// Given two generic trees, return true if they are structurally identical. Otherwise return false.
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

bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    bool truth = true;
    if(root1->children.size()!=root2->children.size()){
        truth = false;
        return truth;
    }
    else{
        for (int i = 0; i < root1->children.size(); i++)
        {
            truth = truth & areIdentical(root1->children[i],root2->children[i]);
        }
    }
    return truth;
}