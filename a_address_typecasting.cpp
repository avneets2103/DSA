#include<iostream>
using namespace std;
int main()
{
    int i = 65;
    int* p = &i;
    char c = i;//Turns to ascii value
    cout<<i<<endl; //65
    cout<<c<<endl; //A
    char* pc = (char*)p;//Explicit type casting
    cout<<*p<<endl;//int takes 4 bytes //65
    cout<<*pc<<endl;//char will look for the one byte only //A
    cout<<*(pc+1)<<endl;//null
    cout<<*(pc+2)<<endl;//null
    cout<<*(pc+3)<<endl;//null
    cout<<p<<endl;//address of integer
    cout<<pc<<endl;//we know that it prints the array till null
    return 0;
}
//memory is stored as:
//{0.0.0.65} WRONG 
//{65.0.0.0} RIGHT thus *pc prints A and *(pc+3) dont print A but null
//This is called Little Endian system i.e. least important kept first and significane increases with bytes.