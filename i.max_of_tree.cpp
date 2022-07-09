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

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    TreeNode<int>* max_node = root;
    for(int i=0; i<root->children.size(); i++){
        if(max_node->data < maxDataNode(root->children[i])->data){
            max_node = maxDataNode(root->children[i]);
        }
    }
    return max_node;
}

int main(){return 0;}
