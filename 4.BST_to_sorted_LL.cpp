#include <iostream>
using namespace std;

template<typename T>
class Node{
    public:
    T data;
    Node* next;
    Node(int data){
        this->data=data;
    }
};

template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    } 
};

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
   if(root==NULL){
    return NULL;
   }
   Node<int>* left;
   Node<int>* right;
   Node<int>* root_node = new Node<int>(root->data);

   if(root->left==NULL && root->right==NULL){
    return root_node;
   } 
   if(root->left==NULL){
    right=constructLinkedList(root->right);
    root_node->next=right;
    return root_node;
   }
   if(root->right==NULL){
    left=constructLinkedList(root->left);
    Node<int>* temp = left;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=root_node;
    return left;
   }
   left=constructLinkedList(root->left);
   right=constructLinkedList(root->right);
   Node<int>* temp = left;
   while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=root_node;
    root_node->next=right;
    return left;
}

