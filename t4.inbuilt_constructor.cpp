//Inbuilt constructors
//
//<copy constructor> 
//<class_name> object_2_name(object_1_name);
//
//<Assignment>
//You can put s2=s1 if both are made and one of them wants the copy of other;
//
//Destructors:
//It comes to action when our scope is at neigh and de allocates the memory
//Yes you can make your own too

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

    ~student() //it normally wont deallocate a pointer object as it is in heap memory thus we need to force the deletion using delete <pointer_object_name>
    {
        cout<<"Destructor called !"<<endl;
    }

    void display()
    {
        cout<<name<<" "<<roll<<" "<<age<<endl;
    }
};

int main(){
    student s1("Avneet",1815,18);//constructor 1
    
    student s2(s1); //copy constructor
    s2.display();

    student* s3= new student("Gargie",1814,18);

    student s4(*s3); //for using copy constructor on a pointer object we have to dereference before using
    //as s3 is just a pointer and nothing else

    student* s5 = new student(*s3); //copy from a pointer object to another

    student s6("Vanshika",1805,18);//Using assignment
    s6=s1;


    student*s7=new student("Akshi");
    *s7=s1;

    cout<<endl<<"Destructor wont work implicitally on pointer objects use delete keyword to free heap memory "<<endl<<endl;

    delete s3; //this line will call destructor 
    delete s5;
    delete s7;

    return 0;}
