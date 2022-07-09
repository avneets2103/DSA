#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<int>* left;
    BinaryTreeNode<int>* right;
    BinaryTreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

void printLevelWise(BinaryTreeNode<int> *root) {
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> unprinted_children;
    unprinted_children.push(root);
    while(unprinted_children.size()!=0){
        BinaryTreeNode<int>* front = unprinted_children.front();
        unprinted_children.pop();
        cout<<front->data<<":L:";
        if(front->left==NULL){
            cout<<-1;
        }
        else{
            cout<<front->left->data;
        }
        cout<<",R:";
        if(front->right==NULL){
            cout<<-1;
        }
        else{
            cout<<front->right->data;
        }
        cout<<endl;
        if(front->left!=NULL){
            unprinted_children.push(front->left);
        }
        if(front->right!=NULL){
            unprinted_children.push(front->right);
        }
    }
}

int main(){return 0;}

