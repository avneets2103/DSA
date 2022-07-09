//traversals
// 1. PreOrder: ROOT -> LEFT -> RIGHT
// 2. Postorder: LEFT -> RIGHT ->ROOT
// 3. Inorder: LEFT -> ROOT -> RIGHT

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

void preOrder(TreeNode<int>* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preOrder(root->children[i]);
    }
}

// bs preorder ko upr neeche krna hai 
void PostOrder(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        PostOrder(root->children[i]);
    }
    cout<<root->data<<" ";
}

