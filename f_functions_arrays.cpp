#include<iostream>
using namespace std;

int sum(int a[], int size)
{
    cout<<sizeof(a)<<endl;
    return 0;
}

int sum2(int*ptr,int size)
{
    int ans=0;
    for(int i=0; i<size;i++)
    {
        ans = ans + ptr[i];
    }
    return ans;
}

int main()
{
    int a[10];
    cout<<sizeof(a)<<endl;//In the main function it prints the size of the full array i.e. 40 here
    cout<<sum(a,10)<<endl;//But when used via function it prints the size of the pointer as an array by default goes in a function like a  pointer
    
    int b[5]={1,2,3,4,5};
    cout<<sum2(b,5)<<endl;

    return 0;
}
