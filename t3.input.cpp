//Input in linked list
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
     
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

void print(Node*head){
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }    
}

Node* take_input(){ //O(N^2)
    //lets use -1 as a terminator here
    int data;
    cin>>data;
    Node*head=NULL;
    while(data != -1){
        // Node n(data); //this is a problema due to scope reasons as node will get deleted after every iteration
        Node* n1 = new Node(data); //thus use dynamics
        if (head==NULL)
        {
            head=n1;
        }
        else{                             //connecting the nodes
            Node*temp=head;
            while(temp->next != NULL){
            temp=temp->next;
            }
            temp->next=n1;
        }
        cin>>data;       
    }
    return head;
}


int main(){
    Node* head=take_input();
    print(head);
    return 0;}
