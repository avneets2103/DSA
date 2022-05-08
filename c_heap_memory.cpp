/*
when we were running programs and allocating memory we were doing this is the stack memory and nt the heap memory (larger memory),
thus here in DMA we use heap memory to write programs
>>Stack: Static Allocation
         Automatic release due to scope
>>Heap: Dynamic allocation [we use the keyword new] and the memory isnt stored by any variable name but we only use the memory, thus 
        we access this data using pointers to store the heap memory.
        No scope issues, it stays and increase data  in heap
        eg: 
        new int; --> Just gives address from the heap //useless
        int*p = new int; --> stores that address from heap //usefull

>>Alwys use delete p; and delete [] arr; so that memory is released all together
*/
#include<iostream>
using namespace std;

int main()
{
    int*p=new int;
    *p=10;
    cout<<"Enter the size of array:"<<endl;
    int n;
    cin>>n;
    int*arr=new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<",";
    }
    delete p;//It deletes the data in the heap as it isnt self released
    delete [] arr;//for deleting an error
    //its very imp to delete later or practical issues encur
    return 0;
}
