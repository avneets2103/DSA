/*
2 integers stores correspondingly in yr code may or maynt be stored in the next address.
BUT This is for sure done in an array
*/
#include<iostream>
using namespace std;

int main()
{
    int i=10;
    int j=24;
    int arr[]={4,6,7,3,6};
    int* p=&i;
    int* ptr=arr; //same as int* ptr = arr[0]; //it by default goes to first element of array.
    cout<<p<<endl;
    p++;
    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<ptr<<endl;
    ptr=ptr+4;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;
    return 0;
}
