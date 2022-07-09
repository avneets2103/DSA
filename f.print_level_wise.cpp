#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class TreeNode {
    public:
    T data;
    vector<TreeNode<T>*> children;
    TreeNode(T data) {
        this->data = data;
    }
};

void printLevelWise(TreeNode<int>* root){
    queue<TreeNode<int>*> unprinted; 
    unprinted.push(root);
    while(unprinted.size()){
        TreeNode<int>* front = unprinted.front();
        unprinted.pop();
        cout<<front->data<<":";
        if(front->children.size()==0){
            cout<<endl;
            continue;
        }
        for (int i = 0; i < front->children.size()-1; i++)
        {
            unprinted.push(front->children[i]);
            cout<<front->children[i]->data<<",";
        }
        unprinted.push(front->children[((front->children).size())-1]);
        cout<<front->children[front->children.size()-1]->data;
        cout<<endl;
    }
}

TreeNode<int>* take_input_level_wise(){
    int rootdata;
    cout<<"Enter root data: "<<endl;
    cin>>rootdata;
    TreeNode<int>* root = new TreeNode<int>(rootdata);
    queue<TreeNode<int>*> unused;
    unused.push(root);
    while (unused.size())
    {
        TreeNode<int>* front = unused.front();
        unused.pop();
        cout<<"Enter number of children of "<<front->data<<endl;
        int child_count; 
        cin>>child_count;
        for (int i = 0; i < child_count; i++)
        {
            int data;
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>data;
            TreeNode<int>* t = new TreeNode<int>(data);
            unused.push(t);
            front->children.push_back(t);
        }
    }
    return root;
} 

int main(){
    TreeNode<int>* root = take_input_level_wise();
    printLevelWise(root);
    return 0;}
