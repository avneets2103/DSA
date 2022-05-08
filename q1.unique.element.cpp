#include<iostream>
using namespace std;

//M1
int findUnique1(int *arr, int n){
    //base
    if (n==0)
    {
        return 0;
    }
    
    int a =0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i]==arr[0])
        {
            a++;
        }
    }
    

    //induction
    if (a==0)
    {
        return arr[0];
    }
    else{
        findUnique1(arr+1,n-1);
    }
}

//M2
int findUnique2(int *arr, int n){
    int i=0;
    int a=0;
    while (i<n)
    {
        a=a^arr[i];
        i++;
    }
    return a;
}

int main(){
    int arr[]={2,3,5,3,2,6,6};
    cout<<findUnique2(arr,7);
    return 0;}
