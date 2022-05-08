#include<iostream>
using namespace std;

class student
{
    private:
    string name;
    int roll;
    int age;

    public:
    //constructors
    student(string a,int b,int age){
        cout<<"Constructor 1"<<endl;
        name = a;
        roll = b;
        this->age = age; //use of " this " 
    }
    student(string name){
        cout<<"Constructor 2"<<endl;
        //name=name; wont work as both r same variables;
        this->name = name; //this is a keyword which stores address of our current object or basically its a chnaging pointer
    }
    student(){
        cout<<"Defualt constructor"<<endl;
    }

    void display()
    {
        cout<<name<<" "<<roll<<" "<<age<<endl;
    }
};

int main(){
    student s1("Avneet",1815,18);//non default constructor or paramterised constructor
    s1.display();//constructor 1
    student* p1 = new student("Gargie"); //for dynamic memory constructor
    p1->display(); //constructor 2
    student s2; 
    s2.display();//dafualt 
    return 0;}
