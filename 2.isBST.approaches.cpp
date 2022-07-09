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

bool isBST(BinaryTreeNode<int> *root) {
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    if(root->left==NULL){
        if(root->data<root->right->data){
            return isBST(root->right);
        }
        return false;
    }
    if(root->right==NULL){
        if(root->data>root->left->data){
            return isBST(root->left);
        }
        return false;
    }
    if(root->left!=NULL && root->right!=NULL){
        if(root->data>root->left->data && root->data<root->right->data){
        return isBST(root->left)&isBST(root->right);
        }
        return false;
    }
}
//the problem here is like this:
//    4 
//  2    6
// 1 10 5 7
//where the right side and left side both are individually bst too, and root->left->data<root->data and root->right->data>root->data
//as every thing on left must be small and vice versa for right

int maximum(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return max(root->data,max(maximum(root->right),maximum(root->left)));
}

int minimum(BinaryTreeNode<int>* root){
    if(root==NULL){
        return INT32_MAX;
    }
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}


//time complexity: O(nh)
bool isBST(BinaryTreeNode<int> *root) {
    if(root==NULL){
        return true;
    }
    int leftMax=maximum(root->left);
    int rightMin=minimum(root->right);

    bool output = (root->data>leftMax) && (root->data<=rightMin) && isBST(root->left) && isBST(root->right);
    return output;
}

//better approach
class isBSTreturn{
    public:
    bool isBST;
    int min;
    int max;
};


//this is O(n) thus much better
isBSTreturn isBST2(BinaryTreeNode<int>* root){
    if(root==NULL){
        isBSTreturn output;
        output.isBST=true;
        output.min=INT32_MAX;
        output.max=INT32_MIN;
        return output;
    }
    isBSTreturn leftOutput=isBST2(root->left);
    isBSTreturn rightOutput=isBST2(root->right);
    int minimum=min(root->data,min(leftOutput.min,rightOutput.min));
    int maximum=max(root->data,max(leftOutput.max,rightOutput.max));
    bool isBSTfinal=(root->data>leftOutput.max)&&(root->data<=rightOutput.min)&&isBST2(root->left).isBST&&isBST2(root->right).isBST;
    isBSTreturn output;
    output.min=minimum;
    output.max=maximum;
    output.isBST=isBSTfinal;
    return output;
}

//another way now 
//constraints 

bool isBST3(BinaryTreeNode<int>* root, int min = INT32_MIN, int max = INT32_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data<min || root->data>max){
        return false;
    }
    bool isLeftOk=isBST3(root->left,min,root->data-1);
    bool isRightOk=isBST3(root->right,root->data,max);
    return isLeftOk && isRightOk;
}