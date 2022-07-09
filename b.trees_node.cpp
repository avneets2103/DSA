/*
A root node will be there, but next we have to store tha address of every of its child in the node.
We are able to achieve this using vectors or a dynamic array of type treeNode* i.e. the array can store the address of upcoming treeNodes
Thus we store the addresss of every child of a parent in its vector named children
*/

#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class Tree_node{
    public:
    T data;
    vector<Tree_node *> children;
    Tree_node(T data){
        this->data=data;
    }
};

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
    return 0;
}


