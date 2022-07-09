/*

<Inspired by binary search>

Binary search tree is a Binary tree where the numbers are stored such that a specific side of the tree has a specific relation with the root->data and the other side will have the exact oppsosite data relation with the root->data.
Generally we take left side as the smaller side and right side as the larger side for every node.

*/

#include<iostream>
using namespace std;

template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

bool searchInBST(BinaryTreeNode<int>* root, int k){
    if(root==NULL){
        return false;
    }
    if(root->data==k){
        return true;
    }
    if(root->data>k){
        return searchInBST(root->left,k);
    }
    if(root->data<k){
        return searchInBST(root->right,k);
    }
}

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
    if(root==NULL){
        return;
    }
    if(k1<root->data){
        elementsInRangeK1K2(root->left,k1,k2);
    }
    if(root->data<=k2 && root->data>=k1){
        cout<<root->data<<" ";
    }
    if(k2>root->data){
        elementsInRangeK1K2(root->right,k1,k2);
    }
}

int main(){return 0;}
