#include<iostream>
#include<string.h>
using namespace std;

class Student{
    public:
    char *name;
    int const age;
    int const roll;

    Student(int a, int r):roll(r),age(a){ //this is a way to allocate memory in this condition as this is the moment where members r made
//      this->age=age;
//      roll=r; //again constant value shows issue as already given garbage value thus we use initialisation lists
        }
    
    //Syntax for initialization list:
    //class_name(arguments):constant_member_name(variable_name){}
    //Note: You can use this for other normal members too wont be an issue
    //Note: Same goes for reference variables
    
    void display(){
        cout<<age<<" "<<roll<<endl;
    }
};

int main(){
    
    int a=5;
    int const b=a; //not allowed if uh initialise const variable first and then provide value
    int &j=a; //not allowed if uh intialise first nd then provide value later
    
    Student s1(18,1815); // we have to initialise the roll number during construction no other ways
    //s1.roll=101; //error here as cant put value into a const variable 
    s1.display();
    return 0;}
