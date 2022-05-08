#include<iostream>
using namespace std;

void inc(int* p)
{
    *p=*p+1;
}
void add_inc(int* p)
{
    p=p+1;
    cout<<p<<endl;
    cout<<*p<<endl;
}

int main()
{
    int a =3;
    cout<<a<<endl;
    inc(&a);
    cout<<a<<endl;
    cout<<&a<<endl;
    add_inc(&a);
    cout<<&a<<endl;
    return 0;
}
