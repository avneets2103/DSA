//Rotate array
#include<iostream>
using namespace std;

void rotate1(int *input, int d, int n)
{
    int emp[d];
    for (int i = 0; i < d; i++)
    {
        emp[i]=input[i];
    }

    for (int i = 0; i < n; i++)
    {
        input[i]=input[i+d];        
    }
    
    for (int i = 0; i < d; i++)
    {
        input[n-d+i]=emp[i];
    }    
}

int main(){
    int arr[]={2,6,3,1,5,9,8};
    rotate1(arr,2,7);
    for (int i = 0; i < 7; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;}
