#include<iostream>
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

BinaryTreeNode<int>* construct_h(int * post, int postS, int postE, int * in, int inS , int inE){
    if(inS>inE || postS>postE){
        return NULL;
    }
    int rootdata=post[postE];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);

    int rootIndex=-1;
    for(int i = inS; i<=inE ;i++){
        if(rootdata==in[i]){
            rootIndex=i;
            break;
        }
    }
    
    int lpostS=postS;
    int lpostE=rootIndex-1;
    int linS=inS;
    int linE=rootIndex-1;
    int rpostS=rootIndex;
    int rpostE=postE-1;
    int rinS=rootIndex+1;
    int rinE=inE;
    
    root->left=construct_h(post,lpostS,lpostE,in,linS,linE);
    root->right=construct_h(post,rpostS,rpostE,in,rinS,rinE);
    return root;
}


BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    return construct_h(postorder,0,postLength-1,inorder,0,inLength-1);
}
