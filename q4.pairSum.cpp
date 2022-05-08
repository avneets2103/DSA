//You have been given an integer array and a number 'num'. Find and return the total number of pairs in the array/list which sum to 'num'.
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
int count_element(int arr[], int n,int x){
    int cnt=1;
    //base
    if (n==0)
    {
        return cnt;
    }
    //induction
    if (arr[0]==x && arr[0]==arr[1])
    {
        cnt=1+count_element(arr+1,n-1,x);
        
    }
    else{
        cnt=count_element(arr+1,n-1,x);
    }
    return cnt;
}

int pairSum(int *arr, int n, int num){
    mergesort(arr,0,n-1);
    int cnt=0;
    int i = 0;
    int j = n-1;
    while (i<j)
    {
        if (arr[i]+arr[j]==num)
        {
            if (arr[i]==arr[j])
            {
                int k=count_element(arr,n,arr[i]);
                int m=(k*(k-1))/2;
                cnt=cnt+1;
                return cnt;
            }      
            int cnt1=count_element(arr,n,arr[i]);
            cout<<cnt1<<endl;
            int cnt2=count_element(arr,n,arr[j]);
            cout<<cnt2<<endl;
            int m=cnt1*cnt2;
            cnt=cnt+m;
            cout<<cnt<<endl;
            i=i+cnt1;
            cout<<i<<endl;
            j=j-cnt2;
            cout<<j<<endl;
        }
        if (arr[i]+arr[j]<num)
        {
            i++;
        }
        if (arr[i]+arr[j]>num)
        {
            j--;
        }
        cout<<endl;
    }

    return cnt;
}

int main(){
    int arr[]={1,3,6,2,5,4,3,2,4};
    cout<<pairSum(arr,9,6);
    return 0;}
