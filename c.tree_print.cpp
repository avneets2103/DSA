//We van use this in a recursive fashion as every tree has many sutrees under it,
//thus we just print the node and leave rest of the work on recursion as shown below

#include<vector>
#include<iostream>
using namespace std;

template <typename T>
class Tree_node{
    public:
    T data;
    vector<Tree_node*> children;
    Tree_node(T data){
        this->data=data;
    }
};

void print_tree(Tree_node<int>* root){
    cout<<root->data<<endl;
    for(int i=0; i<root->children.size() ;i++){
        print_tree(root->children[i]);
    }
}

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

int main(){
    Tree_node<int>* t1 = new Tree_node<int>(10);
    Tree_node<int>* t2 = new Tree_node<int>(20); 
    Tree_node<int>* t3 = new Tree_node<int>(30);
    Tree_node<int>* t4 = new Tree_node<int>(40);
    Tree_node<int>* t5 = new Tree_node<int>(50);
    t1->children.push_back(t2);
    t1->children.push_back(t3);
    t2->children.push_back(t4);
    t2->children.push_back(t5);
    print_tree(t1);
    print_properly(t1);
    return 0;}