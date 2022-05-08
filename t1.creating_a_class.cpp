//Class is a user defined data type
//Every object is a copy of the class
#include<iostream>
using namespace std;

class Student{ 
    public:
    int roll;
    int age;

};

int main(){
    int a = 4; //normal variable creating
    Student s1; //{Static memory} Creating a object of class Student
    Student* s2 = new Student; //Dynamic memory allocation of type Student
    
    s1.age=12;
    s1.roll=1815;
    cout<<s1.age<<endl;
    cout<<s1.roll<<endl;
    
    s2->age=34;
    s2->roll=1805;
    //or//
    // (*s2).age or (*s2).roll // a-> is same as (*a).
    cout<<s2->age<<endl;
    cout<<s2->roll<<endl;
    
    return 0;}
