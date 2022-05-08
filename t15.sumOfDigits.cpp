#include<iostream>
using namespace std;

int sumOfDigits(int n)
{
    if (n==0)
    {
        return 0;
    }
    static int a=0;
    a=n%10+sumOfDigits(n/10);
    return a;
}

int main()
{
    int n;
    cin>>n;
    cout<<sumOfDigits(n);
    return 0;
}
