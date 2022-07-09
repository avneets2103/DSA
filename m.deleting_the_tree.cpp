// as we allocated the trees dynamicallt thus we must delete it purself fromt the heap memory
// we msut not start by deleting the root as if we delete the root, the address of upcoming tree nodes is lost and we had to delete them too, thus for going forward with our task of deletion
// we must first delete the children and then at last delete the root
// this is of type "postOrder" way

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

    ~TreeNode(){
        for(int i = 0; i<this->children.size(); i++){
            delete children[i];
        }
    }
};

// Way 1
void deleteTree(TreeNode<int>* root){
    for (int i = 0; i < root->children.size(); i++){
        deleteTree(root->children[i]);
    }
    delete root;
}

// Way 2 (Destructor method) 
//since we have made our destructor such way thus this will work fine
int main(){
    TreeNode<int>* root;
    delete root;
    return 0;}
