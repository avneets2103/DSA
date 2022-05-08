/* 

*/
#include<iostream>
using namespace std;

void increament1(int**p)
{
    p=p+1;
}
void increament2(int**p)
{
    *p=*p+1;
}
void increament3(int**p)
{
    **p=**p+1;
}

int main()
{
    int i = 5;
    int* p=&i;
    int**q=&p; // q stores the address of p
    cout<<&p<<endl;
    cout<<q<<endl;

    cout<<p<<endl;
    cout<<*q<<endl;

    cout<<i<<endl;
    cout<<*p<<endl;
    cout<<**q<<endl;

    increament1(q);
    cout<<i<<endl<<p<<endl<<q<<endl;

    // increament2(q);
    // cout<<i<<endl<<p<<endl<<q<<endl;

    increament3(q);
    cout<<i<<endl<<p<<endl<<q<<endl;


    return 0;
}
