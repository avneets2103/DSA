#include<iostream>
using namespace std;

int lastIndex(int input[], int size, int x)
{
    static int a = 1;
    if (size<a)
    {
        return -1;
    }
    if (input[size-a]==x)
    {
        return size-a;
    }
    else
    {
        a++;
        return lastIndex(input,size,x);
    }   
}

int main()
{
    int size,x;
    cin>>size>>x;
    int* input=new int[size];
    for (int i = 0; i < size; i++)
    {
        cin>>input[i];
    }
    cout<<lastIndex(input,size,x);
    return 0;
}