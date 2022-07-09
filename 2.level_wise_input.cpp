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

BinaryTreeNode<int>* take_input_level_wise(){
    int root_data;
    cout<<"Enter data"<<endl;
    cin>>root_data;
    if(root_data==-1){
        return NULL;
    }
    queue<BinaryTreeNode<int>*> unseen_nodes;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(root_data);
    unseen_nodes.push(root);
    while(unseen_nodes.size()!=0){
        BinaryTreeNode<int>* front = unseen_nodes.front();
        unseen_nodes.pop();
        cout<<"Enter the left children of "<<front->data<<endl;
        int left_data;
        cin>>left_data;
        if(left_data!=-1){
            BinaryTreeNode<int>* left_node=new BinaryTreeNode<int>(left_data);
            front->left=left_node;
            unseen_nodes.push(left_node);
        }
        
        int right_data;
        cout<<"Enter the right children of "<<front->data<<endl;
        cin>>right_data;
        if(right_data!=-1){
            BinaryTreeNode<int>* right_node=new BinaryTreeNode<int>(right_data);
            front->right=right_node;
            unseen_nodes.push(right_node);
        }
    }
    return root;
}

int main(){return 0;}
