#include<iostream>
using namespace std;

double geometricSum(int k)
{
    double term=1;
    for (int i = 1; i <= k; i++)
    {
        term = term/2;
    }
    if (k==0)
    {
        return 1;
    }
    return term+geometricSum(k-1);    
}

int main()
{
    int k;
    cin>>k;
    cout<<geometricSum(k);
    return 0;
}
