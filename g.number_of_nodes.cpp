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

int number_of_nodes(TreeNode<int>* root){
    //base
    if(root->children.size()==0){
        return 1;
    }
    //induction
    int descendent_sum=0;
    for (int i = 0; i < root->children.size(); i++)
    {
        descendent_sum+=number_of_nodes(root->children[i]);
    }
    return 1+descendent_sum;
}

int main(){return 0;}
