//BST class

#include<iostream>
using namespace std;

template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    } 
};

class BST{
    BinaryTreeNode<int>* root;
    public:
    BST(){
        root=NULL;
    }
    ~BST(){
        delete root;
    }
    
    private: 
    void removeh(int data,BinaryTreeNode<int>* node){
        if(node==NULL){
            return;            
        }
        if(node->left==NULL && node->right==NULL && node->data==data){
            node=NULL;
            return;
        }
    }
    public:
    void remove(int data){
        removeh(data,root);
    }
    
    private:
    void inserth(int data, BinaryTreeNode<int>* node){
        if(node==NULL){
            node=new BinaryTreeNode<int>(data);
        }
        int root_data=node->data;
        if(data<root_data){
            inserth(data,node->left);
        }
        else if(data>root_data){
            inserth(data,node->right);
        }
    }

    public: 
    void insert(int data){
        inserth(data,root);
    }

    private:
    bool hasDatah(int data, BinaryTreeNode<int>* node){
        if(node==NULL){
            return false;
        }
        if(root->data==data){
            return true;
        }
        if(root->data>data){
            return hasDatah(data,node->left);
        }
        if(root->data<data){
            return hasDatah(data,node->right);
        }
    }

    public:
    bool search(int data){
        return hasDatah(data,root);
    }
};

int main(){return 0;}
