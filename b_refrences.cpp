/*
for refrenceing we use &
it can also be used for changing values in functions without using pointers

always give the variable to refer to the reference variable or it shows error
*/
#include<iostream>
using namespace std;

void increament(int &x)
{    
    x++;
}

int main()
{
    int i = 10;
    int j = i;//Normally a new variable is made to assign it value
    int &k = i;//referencing to same memory just gives other name to same address 
    increament(i);
    cout<<i<<endl;
    cout<<j<<endl;
    cout<<k<<endl;
    increament(k);
    cout<<i<<endl;
    cout<<j<<endl;
    cout<<k<<endl;
    return 0;
}
