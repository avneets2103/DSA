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

bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    bool ans = false;
    if (root == NULL)
    {
        return false;
    }
    if (root->data == x)
    {
        ans = true;
        return ans;
    }
    ans = isNodePresent(root->left, x) | isNodePresent(root->right, x);
    return ans;
}
int level_of_node(BinaryTreeNode<int>* root,int x){
    if(root==NULL){
        return -1;
    }
    if(root->data==x){
        return 1;
    }
    if(isNodePresent(root->left,x)){
        return 1+level_of_node(root->left,x);
    }
    else{
        return 1+level_of_node(root->right,x);
    }
}
void printLevelWise(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL){
        return;
    }
     queue<BinaryTreeNode<int> *> pn;
    
    pn.push(root);
    pn.push(NULL);
    
    while(pn.size()!=0)
    { 
        BinaryTreeNode<int> *front=pn.front();
        pn.pop();
        
       if(front==NULL)
       {  if(pn.size()==0)
           break;
         cout<<endl;
          pn.push(NULL);
       }
        
     else
     { cout<<front->data<<" ";
     
        if(front->left)
        pn.push(front->left);
        if(front->right)
         pn.push(front->right);
     }
    }