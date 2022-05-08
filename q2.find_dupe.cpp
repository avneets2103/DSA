#include<iostream>
using namespace std;

int findDuplicate(int *arr, int n)
{
    int sum=0;
    for(int i=0;i<n;i++){
        sum = sum + arr[i];
    }
    //and 
    int og_sum=((n-2)*(n-3))/2;
    return sum-og_sum;
}

int main(){
    int arr[]={0,2,4,3,1,2};
    cout<<findDuplicate(arr,6);
    return 0;}
