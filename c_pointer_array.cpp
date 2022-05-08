/*
&arr[0]=arr (same thing)
*(a+i)--->a[i]
i[a]=a[i] 
*/
#include<iostream>
using namespace std;

int main()
{   
    char c[]={'a','b','c'};
    char* ptr2=&c[2];
    cout<<sizeof(c[2])<<endl;
    cout<<sizeof(c)<<endl;
    cout<<sizeof(*ptr2)<<endl;
    cout<<sizeof(ptr2)<<endl;
    int arr[]={1,2,3,5,6,7};
    int* ptr=arr;
    for (int i =0 ; i < 6; i++)
    {
        cout<<*ptr<<",";
        ptr++;
    }
    return 0;
}
