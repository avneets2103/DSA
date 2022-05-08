#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next; //address of a node thus a node pointer
    
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

void print(Node*head){
    Node*temp=head; //we use temp as if we are using head we are actually using our head address which is risky.
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

void print2(Node*head){
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    Node n1(1);
    Node*head=&n1;
    Node n2(2),n3(3),n4(4),n5(5);
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=&n5; 
    print(head); //call by value
    cout<<endl;
    print2(head); //call by value
    cout<<endl;
    print2(head); //call by value
    cout<<endl;
}