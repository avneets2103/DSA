//inroder: full_left->root-> full_right
//preorder: root->full_left->full_right
//postorder: full_left->full_right->root

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

BinaryTreeNode<int>* buildTreeh_preorder(int* pre, int preS, int preE, int* in, int inS, int inE){
    if(inS>inE||preS>preE){
        return NULL;
    }
    int rootData=pre[preS];
    int rootIndex=-1;
    for (int i = inS; i <= inE; i++)
    {
        if(rootData==in[i]){
            rootIndex=i;
            break;
        }
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left=buildTreeh_preorder(pre,preS+1,preS+(rootIndex-inS),in,inS,rootIndex-1);
    root->right=buildTreeh_preorder(pre,preS+(rootIndex-inS)+1,preE,in,rootIndex+1,inE);
    return root;
}

BinaryTreeNode<int>* buildTree(int* preorder, int preLength, int* inorder, int inLength){
    return buildTreeh_preorder(preorder,0,preLength-1,inorder,0,inLength-1);
}

BinaryTreeNode<int>* buildTreeh_postorder(int* post,int postS, int postE, int* in, int inS, int inE){
    if(inS>inE || postS > postE){
        return NULL;
    }
    int rootdata=post[postE];
    int rootIndex=-1;
    for(int i = inS; i<inE ;i++){
        if(rootdata==in[i]){
            rootIndex=i;
            break;
        }
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
    root->left=buildTreeh_postorder(post,postS,rootIndex-1,in,inS,rootIndex-1);
    root->right=buildTreeh_postorder(post,rootIndex,postE-1,in,rootIndex+1,inE);
    return root;
}

BinaryTreeNode<int>* buildTree2(int *postorder, int postLength, int *inorder, int inLength) {
    return buildTreeh_postorder(postorder,0,postLength-1,inorder,0,inLength-1);
}
