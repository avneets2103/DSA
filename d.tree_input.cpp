#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class Tree_node{
    public:
    T data;
    vector<Tree_node*> children;
    Tree_node(int data){
        this->data=data;
    }
};

void print_properly(Tree_node<int>* root){
    cout<<root->data<<" : ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0; i<root->children.size() ;i++){
        print_properly(root->children[i]);
    }
}

Tree_node<int>* take_input_1(){
    int root_data;
    cout<<"Enter data: "<<endl;
    cin>>root_data;
    Tree_node<int>* root = new Tree_node<int>(root_data);
    cout<<"Enter number of children of "<<root_data<<endl;
    int child_count;
    cin>>child_count;
    for (int i = 0; i < child_count; i++)
    {
        Tree_node<int> *child_node =  take_input_1();
        root->children.push_back(child_node);
    }
    return root;
}

int main(){
    Tree_node<int>* root = take_input_1();
    print_properly(root);
    return 0;}

