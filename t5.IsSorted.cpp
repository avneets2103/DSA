#include<iostream>
using namespace std;

bool sorted(int a[], int size)
{
    if (size==0 || size==1)
    {
        return true;
    }
    if(a[0]>a[1])//compare starting 2
    {
        return false;
    }
    bool small_sorted = sorted(a+1,size-1);//if a[0]<a[1] then we will check similarly for the rest of the array left with one less element and one size less.
    if (small_sorted == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int a[5]={2,4,5,6,8};
    cout<<sorted(a,5);
    return 0;
}
