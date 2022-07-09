#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template<typename T>
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

Tree_node<int>* take_input_level_wise(){
    queue<Tree_node<int>*> uninteracted_nodes;
    int root_data;
    cin>>root_data;
    Tree_node<int> * root = new Tree_node<int>(root_data);
    uninteracted_nodes.push(root);
    while(uninteracted_nodes.size()!=0){
        Tree_node<int>* front = uninteracted_nodes.front();
        uninteracted_nodes.pop();
        cout<<"Enter number of children of "<<front->data<<endl;
        int numChild;
        cin>>numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;
            Tree_node<int>* child = new Tree_node<int>(childData);
            front->children.push_back(child);
            uninteracted_nodes.push(child);
        }    
    }
    return root;
}

int main(){
    Tree_node<int>* root = take_input_level_wise();
    print_properly(root);
    return 0;}
