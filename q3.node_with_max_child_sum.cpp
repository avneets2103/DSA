// Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.
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

int child_sum(TreeNode<int>* root){
    int child_sum=0;
    for (int i = 0; i < root->children.size(); i++)
    {
        child_sum+=root->children[i]->data;
    }
    return child_sum;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    int root_sum=0;
    TreeNode<int>* max_node_of_children=root;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int>* this_sum = maxSumNode(root->children[i]);
        if(child_sum(this_sum) > child_sum(max_node_of_children)){
            max_node_of_children=this_sum;
        }
    }
    return max_node_of_children;
}