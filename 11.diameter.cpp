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

//Time complexity: O(nlogn)= O(nh) for perfectly balanced binary tree
//Time complexity: O(n^2) = O(nh) for perfect inbalance
//Here h is the height
//Thus time complexity is nh 

int height(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}

int diameter(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int option1=height(root->left)+height(root->right);
    int option2=diameter(root->left);
    int option3=diameter(root->right);
    return max(option1,option2,option3);
}

// this is an inbuilt pair class avaialable in c++ where the variables are first and second
//Why we need better approach and where is the problem in original approach? 
//Basically we are calling for both the diameter of the left and right nodes and then again calling for the height, hwihc doubles the work as we are calling the same node twice for different data, thus we rather call them together in a pair so that we can reduce the amount of work.


//Time complexity: O(n) always
pair<int,int> diameter_better_app(BinaryTreeNode<int>* root){
    if(root==NULL){
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }

    pair<int,int> leftAns=diameter_better_app(root->left);
    pair<int,int> rightAns=diameter_better_app(root->right);
    //considering first as height and second as diameter
    int height=1+max(leftAns.first,rightAns.first);
    int diameter=max(leftAns.first+rightAns.first,max(leftAns.second,rightAns.second));
    
    pair<int,int> p;
    p.first=height;
    p.second=diameter;
    return p;
}
