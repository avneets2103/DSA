//You have been given an integer array/list(ARR) of size N. It has been sorted(in increasing order) and then rotated by some number 'K' in the right hand direction.
//Your task is to write a function that returns the value of 'K', that means, the index from which the array/list has been rotated.
#include<iostream>
using namespace std;

void merge(int arr[],int start,int mid,int end)
{
    int n1=mid-start+1;
    int n2=end-mid;
    int l[n1],m[n2];
    for(int i=0;i<n1;i++)
    {
        l[i]=arr[start+i];
    }
    for(int j=0;j<n2;j++)
    {
        m[j]=arr[mid+1+j];
    }
    int i=0;
    int j=0;
    int k=start;
    while(i<n1&&j<n2)
    {
        if(l[i]<m[j])
        {
            arr[k]=l[i];
            k++;
            i++;
        }
        else
        {
            arr[k]=m[j];
            k++;
            j++;
        }
    }
    while(i<n1)
    {
        arr[k]=l[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k]=m[j];
        k++;
        j++;
    }
}
void mergesort(int arr[],int start,int end)
{
    if(start<end)
    {
        int mid=(start+end)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}

int arrayRotateCheck(int *input, int size){
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i]=input[i];
    }
    mergesort(arr,0,size-1);
    int i = 0;
    for (;1; i++)
    {
        if (input[i]==arr[0])
        {
            break;
        }
    }
    return i;
}

int main(){
    int arr[]={5,6,1,2,3,4};
    cout<<arrayRotateCheck(arr,6);
    return 0;
}