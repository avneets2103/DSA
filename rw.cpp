#include <iostream>
using namespace std;
int main()
{
    int i,j,k,n;
    cout<<"enter the number of rows:";
    cin>>n;
    for(j=1;j<=n;j++)
    {
        for(i=1;i<=n-j;i++)
        {
            cout<<" ";
        }
        for(k=1;k<=j;k++)
        {
            cout<<"*";
        }
        cout<<"\n";
    }
}

