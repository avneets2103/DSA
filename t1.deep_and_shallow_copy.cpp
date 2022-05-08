#include<iostream>
#include<string.h>
using namespace std;

class Student{
    int age;
    char *name;

    public:
    Student(int age, char *name){
        this->age=age;
        
        //Shallow copy or basically just using addresses and not full array in copy
        //this->name=name;
        
        //Deep copy
        this->name=new char[strlen(name)+1]; //+1 for null character
        strcpy(this->name,name); //adding name form parameter to new array formed
    }
    void display(){
        cout<<age<<" "<<name<<endl;
    }
};

int main(){
    Student s1(18,"avneet");
    s1.display();
    return 0;}
