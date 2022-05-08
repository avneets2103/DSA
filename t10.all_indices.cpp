#include<iostream>
using namespace std;

int allIndexes(int input[], int size,int x, int output[])
{
    if (size == 0) 
    {
        return 0;
    }
 
    int smallAns = allIndexes(input + 1,size - 1, x, output);
    if (input[0] == x) 
    {
        for (int i = smallAns - 1; i >= 0; i--) 
        {
            output[i + 1] = output[i] + 1;
        }
        output[0] = 0;
        smallAns++;
    }
    else 
    {
        for (int i = smallAns - 1; i >= 0; i--) 
        {
            output[i] = output[i] + 1;
        }
    }
    return smallAns;
}
void AllIndexes(int input[], int n, int x)
{
    int output[n];
    int size = allIndexes(input, n,
                                x, output);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
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
    return 0;
}
