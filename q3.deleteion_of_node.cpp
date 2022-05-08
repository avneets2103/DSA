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

int length(Node *head){
    int a=0;
    while (head != NULL)
    {
        a++;
        head=head->next;
    }
    return a;
}


Node* deleteNode(Node *head, int pos){
    Node* t=head;
    int len=length(t);
    if(pos>len-1){
        return head;
    }
    for (int i = 0; i < pos-1; i++)
    {
        t=t->next;
    }
    if (pos==0)
    {
        t=t->next;
        return head;
    }
    
    Node*temp=t->next;
    t->next=temp->next; 
    return head;
}