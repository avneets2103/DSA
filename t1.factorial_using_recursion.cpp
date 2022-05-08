/*
Recursion: 
Note: 
1. We must first know where the recursion is occuring
2. We must set a standard to stop the recursion and put output for a smaller problem nd then use it for getting bigger answers or outputs.
3. It works with call stack
*/
#include<iostream>
using namespace std;

int fact(int n)
{
    if (n==0)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}

int main()
{
    cout<<"enter n: "<<endl;
    int n;
    cin>>n;
    cout<<fact(n);
    return 0;
}
