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

int sum_of_nodes(TreeNode<int>* root){
    //base
    if(root->children.size()==0){
        return root->data;
    }
    //
    int descendentsum=0;
    for (int i = 0; i < root->children.size(); i++)
    {
        descendentsum+=sum_of_nodes(root->children[i]);
    }
    return root->data+descendentsum;
}

int main(){return 0;}
