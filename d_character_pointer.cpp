//character pointers behave different
//character pointer dont give address but prints the whole thing or array; 
#include<iostream> 
using namespace std;

int main()
{
    int x[]={1,2,3,4,5};
    cout<<*x<<endl;//prints element 0
    cout<<x<<endl;//prints address of array 
    char a[]="abc";
    cout<<*a<<endl;//prints element 0
    cout<<a<<endl;//prints the whole array content until it finds a null character
    
    char*ptr1=&a[0];
    cout<<ptr1<<endl;//expected to get address of the the element in memory, but result is the whole array content 
    
    char c1='a';
    char*ptr2=&c1;
    cout<<ptr2<<endl;
    return 0;
}
