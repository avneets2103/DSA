//DATA STRUCTURES

//1.Linked list:
//Its a linear DS which are not stored in contigious location in memory but elements are linked by pointers
//Here we just store the address of 1st element, and the first element have its value stored along with address of 2nd element and goes on.
//But to store both value and address in some location we dont have any predefined data type
//So we use "CLASSES" as its is user defined data type

//The initial element is called as a head
//Always save the address of head
//Tail is the end of the linked list which as NULL as its address saved or tail.next
//Here we call every element (value and address) as NODE
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

int main(){
    //statically
    Node n1(1),n2(2); //making nodes
    Node*head=&n1; //daving head address
    n1.next=&n2; //linking
    cout<<"value of first is: "<<head->data<<endl;
    cout<<"value of second is: "<<head->next->data<<endl;
    
    //dynamically
    Node* n3= new Node(3);
    Node* n4= new Node(4);
    Node*head2=n3;
    n3->next=n4;
    cout<<"value of third is: "<<head2->data<<endl;
    cout<<"value of fourth is: "<<head2->next->data<<endl;
    return 0;}
