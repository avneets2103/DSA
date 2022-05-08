//for using any private property we need a public function.
#include<iostream>
using namespace std;

class student
{
    int age;
    
    public:
    int roll;
    void display(){
        cout<<age<<" "<<roll; //private prooperties can be accessed inside the class
    }
    int getAge(){
        cout<<"Enter age: ";
        cin>>age;
    }

    void setage(int n_age){
        age = n_age;    
    }
};

int main(){
    student s1;
    s1.roll=1815;
    s1.getAge();
    s1.display();
    s1.setage(25);
    s1.display();
    return 0;}
