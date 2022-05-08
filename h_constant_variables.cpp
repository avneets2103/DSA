/*
1. Constant variables: A storage which only permits reading and uh have to provide it data then and there only.
2. Constant refrence: if i make const int& q=j; then this lines says that j can be varied but q must nt be varied like q++(no) j++(okay) 
3. Constant reference from constant variable is also allowed but no way uh can change data any ways.
4. Access: You can provide a lower access or equal access but nt higher access
eg: int const i = 12;
    int &k=i; <wrong> 
    int const &k = i; <right>
eg: int const i1 = 10;
    int*p=&i1; <wrong>
    int const*p=&i1; <right>  
eg: int j1 = 10;
    int*p=&i1; <right too> //can change using this pointer
    int const*ptr=&i1; <right> //cant change using this pointer as it only has read access      
5. Constant argument: Even when using a pointer or by refrence method in function we can provide only the read access.
*/
#include<iostream>
using namespace std;

void g(const int& a)
{
    //a++; //nt allowed now
}

void f(const int* p)
{
    //p++; //nt allowed now
}

int main()
{
    int i = 10;
    const int k = i;
    const int & q = i;
    cout<<i<<endl;
    cout<<k<<endl;
    cout<<q<<endl;
    i++;
    cout<<i<<endl;//changes
    cout<<k<<endl;//its a constant thus it dont chnages once assigned
    cout<<q<<endl;//it is a reference variable thus it constantly points to i only or address of i only.
 

    int const j2 = 12;
    //int & k = j2; //nt allowed as j2 itself only has read access, thus the pointer cant have write access too
    int const& k = j2; //works fine as it has given read access only here
    // const int & j3 = j2;

    int const i1 = 10;
    //int*p=&i1;//nt allowed as again this will provde pointer a write access using * by a varaible which itslef only had read access
    int const*p=&i1;

    int const*a=&i;
    int j = 12;
    a = &j; //allowed as the pointer a is pointing to a const value but itself its nt a constant
    //but
    int*const b= &j;
    (*b)++;
    cout<<j<<endl;
    //a1 = &j; //nt allowed as this pointer is constant now 
    return 0;
}
