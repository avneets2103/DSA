#include<iostream>
using namespace std;

int countZeros(int n)
{
    static int a=0;
    if (n<10 && n>0)
    {
        return 0;
    }
    if (n==0)
    {
        return 1;
    }
    else if(n%10==0)
    {
        return 1+countZeros(n/10);
    }
    return countZeros(n/10);      
}

int main()
{
    int n;
    cin>>n;
    cout<<countZeros(n);
    return 0;
}
