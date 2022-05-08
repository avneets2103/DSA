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

void intersection(int *arr1, int *arr2, int n, int m) 
{
    mergesort(arr1,0,n-1);
    mergesort(arr2,0,m-1);
    int i=0,j=0;
    while (i<n && j<m)
    {
        if (arr1[i]==arr2[j])
        {
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
        else if (arr1[i]>arr2[j])
        {
            j++;
        }
        else{
            i++;
        }
    }
}


int main(){
    int arr1[7]={6,2,6,2,1,9,8};
    int arr2[5]={3,6,8,2,9};
    intersection(arr1,arr2,7,5);
    return 0;}
