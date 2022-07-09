#include<iostream>
#include<vector>
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

template <typename T>
class Node {
	public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data=data;
        this->next=NULL;
    }
};

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    vector<Node<int>*> v;
    Node<int>* head = new Node<int>(root->data);
    v.push_back(head);
        
    vector<Node<int>*> l = constructLinkedListForEachLevel(root->left);
}