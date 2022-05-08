/*
Benifits: 
1. Not everytime uh need to define new variable thus memory is saved
2. Easy to access and change from anywhere
3. Easy to pass in functions and dont need arguments

Problems: 
If you use global variable then many changes will occur thus dangerous to use
*/
#include<iostream>
using namespace std;

int a;//this is a global varaible as uh can access it everywhere in the code

void g()
{
    a++;
    cout<<a<<endl;
}

void f()
{
    cout<<a<<endl;
    a++;
    g();
}

int main()
{
    a=10;
    f();
    cout<<a<<endl;
    return 0;
}
