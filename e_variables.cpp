/*
defining a variable is better as it saves memory and its easy to maintain the code
it wont work like pi++ X wrong X
*/
#include<iostream>
using namespace std;
#define pi 3.14 //new method to do so

int main()
{
    //old method
    //double pi = 3.14;
    cout<<"enter r :"<<endl;
    int r;
    cin>>r;
    double area = pi*r*r;
    cout<<area<<endl;
    return 0;
}
