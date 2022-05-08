/*
Problems with inline functions:
The a.exe file gets very heavy as a lot of code is there now.
So dont turn every function to a inline function, only yhe one which are max 3 line functions are to be taken for this job.
*/

#include<iostream>
using namespace std;

inline int max(int a, int b)//inline is used as function will take more time 
{
    return (a>b)?a:b;  //if true then a allot else b allot
}

int main()
{
    int x,y;
    cout<<max(x,y)<<endl;
    return 0;
}
