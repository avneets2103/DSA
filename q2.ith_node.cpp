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

//APP1 (Not to use)
void printIthNode(Node* head, int i){
    if (i==0)
    {return;}
    while (head != NULL)
    {
        for (int a = 0; a < i; a++)
    {
        head=head->next;
    }
    cout<<head->data;
    }
    
}

//APP2 (BETTER)
void printIthNode2(Node* head,int i){
    Node*current=head;
    int count=0;
    while (current !=NULL)
    {
        if(count==i){
            cout<<current->data;
        }
        count++;
        current=current->next;
    }
}

int main() {
    return 0;}
