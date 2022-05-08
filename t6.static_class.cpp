#include<iostream>
using namespace std;

//static properties belong to a class and not a object

class student
{
    public:
    int roll;
    int age;
    
    student(int a, int b){
        roll=a;
        age=b;
        total_count++;
    }
    void display(){
        cout<<roll<<" "<<age<<endl;
    }
    int total_student;//this property dont exsist for a person but for a class
    static int total_count;//belongs only to the class
    // total_count=0; //Cant initialise like this as it is a property of the whole class
    
    static int getTotalStudent(){
        return total_count;
    } 
    //this property belongs to the class
    //used by:
    //student::getTotalStudent();

    //static properties can only use static members and no one else
    //The static properties dont have any this pointer for use.
};

int student::total_count=0;

int main(){
    student s1(1815,18),s2(1805,18);
    cout<<s1.total_count<<endl; //property dont belongs to a specific object thus we need another way to call this data    
    student s3(1846,18);
    s1.display();
    s2.display();
    s3.display();
    cout<<student::total_count<<endl; //better approach
    
    cout<<student::getTotalStudent();
    
    return 0;}

//Syntax of static member:
//<var_type> <class_name>::<variable_name>=<value>;

//Syntax of static property:
//