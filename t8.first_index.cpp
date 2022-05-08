#include<iostream>
using namespace std;

int firstIndex(int input[], int size, int x)
{
    static int a = 0;//it isnt  aconst but it doesnt re evaluates after every loop from begining
    if (size==0)
    {
        return -1;
    }
    if (input[0]==x)
    {
        return a;
    }
    else
    {
        a++;
        return firstIndex(input+1,size-1,x);
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
    cout<<firstIndex(input,size,x);
    return 0;
}



