//searcing a node in the list.
#include<iostream>
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
//approach 1
int findNode(Node *head, int n){
    int cnt=0;
    while(head->data != NULL){
        if (head->data==n)
        {
            return cnt;
        }
        cnt++;
    }
    return -1;
}

//Approach 2 [Better]
int length(Node *head){
    int a=0;
    while (head != NULL)
    {
        a++;
        head=head->next;
    }
    return a;

}


int findNode(Node *head, int n){
    int l=length(head);
    //base
    static int cnt = 0;
    cnt++;
    if (l==0)
    {
        return -1*cnt;
    }
    //induction
    if (head->data==n)
    {
        return 0;
    }
    return 1+findNode(head->next,n);
}