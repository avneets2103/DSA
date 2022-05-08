#include<iostream>
using namespace std;

int sum_array(int a[],int size)
{
    if (size==0)
    {
        return 0;
    }
    if (size==1)
    {
        return a[0];
    }
    int solution = a[0]+sum_array(a+1,size-1);
    return solution;
}

int main()
{
    int size;
    cin>>size;
    int* ptr=new int[size];
    for (int i = 0; i < size; i++)
    {
        cin>>ptr[i];
    }
    cout<<sum_array(ptr,size);
    return 0;
}
