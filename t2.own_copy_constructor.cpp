#include<iostream>
#include<string.h>
using namespace std;

class Student{
    int age;
    
    public:
    char *name;
    Student(int age, char *name){
        this->age=age;
        
        //Shallow copy or basically just using addresses and not full array in copy
        //this->name=name;
        
        //Deep copy
        this->name=new char[strlen(name)+1]; //+1 for null character
        strcpy(this->name,name); //adding name form parameter to new array formed
    }

    //making_my_own_copy_constructor
    /* 
    Student(Student s){ //student s = main.s1 //we are already using copy constructor here that is a issue
        this->age=s.age;
        this->name=new char[strlen(s.name)+1]; //deep copying
    }
    */

    Student(Student &s){ //thus we use this so that rather than using copy constructor then we use reference 
        this->age=s.age;
        this->name=new char[strlen(s.name)+1];
    }
    
    void display(){
        cout<<age<<" "<<name<<endl;
    }
};

int main(){
    Student s1(20,"abcd");
    s1.display();
    Student s2(s1); //shallow copy occurs here too for inbuilt thus we need our won copy constructor
    s2.name[0]='x';
    s2.display();
    s1.display();
    return 0;}
