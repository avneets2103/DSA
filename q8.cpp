#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
int length(Node* head){
    int cnt=0;
    while(head != NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}

Node *appendLastNToFirst(Node *head, int n)
{
    int l=length(head);
    Node*temp2=head;
    Node*temp=head;
    if(n>l){
        return NULL;
    }
    if (n==0)
    {
        return head;
    }
    
    for (int i = 0; i < l-n-1; i++)
    {
        temp=temp->next;
    }
    Node* new_head=temp->next;
    
    for (int i = 0; i < l-1; i++)
    {
        temp2=temp2->next;   
    }
    temp2->next=head;
    temp->next=NULL;
    return new_head;
}
