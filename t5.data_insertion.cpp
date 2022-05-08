#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

Node* in(){
    int data;
    do
    {
    cin>>data;
    Node*head=NULL;
    Node*tail=NULL;
    Node* newdata = new Node(data);
        if (head==NULL)
        {
            head=newdata;
            tail=newdata;
        }
        else{
            tail->next=newdata;
            tail=tail->next;
        }
        return head;}
    while (data != -1);
}

void print(Node* head){
    Node*temp=head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insert(Node* head,int pos,int value){ //same can be done with count varaible
    Node* new_node=new Node(value); //making a new node
    for (int i = 0; i < pos-1; i++) //reaching the just previous node 
    {
        head=head->next;
    }
    Node* next_add=head->next; //storing the address stored in prev node or the address of next node
    new_node->next=next_add; //giving the address of next to our inserted node
    head=new_node; //proving address of our inserted node to prev. node
}

int main(){
    Node* head=in();
    print(head);
    insert(head,3,100);
    print(head);
    return 0;}
  