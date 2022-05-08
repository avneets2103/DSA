#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

Node* deleteNodeRec(Node *head, int pos) {
   if(pos==0){
       head=head->next;
       return head;
   }
   Node* x=deleteNodeRec(head->next,pos-1);
   head->next=x;
}