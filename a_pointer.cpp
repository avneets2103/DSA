//&:{address of} 
//pointers are variables which store address of other variables.
//storage pe phunchne ke 2 tareeke hai ab: thru i or p
//*:{dereference operator}

#include<iostream>
using namespace std;
int main(){
    int i=10;
    int* p= &i;
    cout<<&i<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<sizeof(p)<<endl;
    return 0;}
