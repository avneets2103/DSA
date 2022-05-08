/*
for allocating a 2d array in a heap we can directly just go and type new int [x][y];...
if we think int[x][y] i.e. a 2d array is nothing else but here we are using x rows to store x 1d arrays which contain y elements each
so we are basically making x arrays in the heap and alloing the array address to x different pointers which are stored in the heap and those pointers are stored in stack memory

//2D Dynamic memory in heap

    int**p=new int*[x]; //p is the pointer pointing to the array which contains pointers as the elements
    for (int i=1; i<=y; i++)
    {
        p[i]=new int[y];//here we are allocating y different arrays to the pointers we have in the array pointed by p. 
    }

//Deletion of 2d arrays
    for (int i = 1; i <= x; i++)
    {
        delete [] p[i];
    }
    delete [] p;
        
Jagged array is an array of variable size

*/
#include<iostream>
using namespace std;

int main()
{
    cout<<"Enter the row count of the 2d array: "<<endl;
    int x,y;
    cin>>x;
    cout<<"Enter the column count of the 2d array: "<<endl;
    cin>>y;
    //making 2d arrays in heap
    int**p=new int*[x]; //p is the pointer pointing to the array which contains pointers as the elements
    for (int i=1; i<=y; i++)
    {
        p[i]=new int[y];//here we are allocating y different arrays to the pointers we have in the array pointed by p. 
    }
    cout<<"Enter the elements: "<<endl;
    for (int i = 1; i<=x; i++)
    {
        for (int j = 1;j<=y; j++)
        {
            cin>>p[i][j];//i th row 5th element or ith array and 5th element of tht array
        }    
    }
    for (int i = 1; i<=x; i++)
    {
        for (int j = 1;j<=y; j++)
        {
            cout<<p[i][j]<<" ";
        }    
        cout<<endl;  
    }
    for (int i = 1; i <= x; i++)
    {
        delete [] p[i];
    }
    delete [] p;
    return 0;
}
