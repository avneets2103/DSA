#include<iostream>
using namespace std;

class Node{
    public:
	int data;
	Node *next;
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

Node* insertNode(Node *head, int i, int data) {
    //induction
    Node* n=new Node(data);
    if (i==0)
    {
        n->next=head;
        return n;
    }
    Node*temp=insertNode(head->next,i-1,data);
    head->next=temp;
}

int main(){return 0;}
