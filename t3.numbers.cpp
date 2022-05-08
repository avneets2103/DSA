#include<iostream>
using namespace std;

int print(int n)
{
    const int x = n;
    if (n==1)
    {
        return 1;
    }
    else
    {
        return x-(n-1);
    }
}

int main()
{
    int n;
    cin>>n;
    cout<<print(n);
    return 0;
}
