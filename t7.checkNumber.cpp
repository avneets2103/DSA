#include<iostream>
using namespace std;

bool checkNumber(int input[],int size,int x)
{
    if (size==0)
    {
        return false;
    }
    if (input[0]==x)
    {
        return true;
    }
    else
    {
        checkNumber(input+1,size-1,x);
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
    cout<<checkNumber(input,size,x);
    return 0;
}
