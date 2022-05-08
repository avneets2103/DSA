/*
Operator overloading:
You can also return a fraction as given in add2 property before.
But what if i wanna use a operator for this rather than calling a function
Use the keyword operator
*/

#include<iostream>
using namespace std;

class fraction{
    int num;
    int den;
    
    public:
    fraction(int num,int den){
        this->num=num; //this operator use
        this->den=den;
    }
    void display() const
    {
        cout<<num<<"/"<<den<<endl;
    }
    void add(fraction f){
        num=(num*f.den + f.num*den); //num goes for f1 and f.num goes for parameterised object
        den=f.den*den;
    }
    
    fraction add2(fraction f){            //we can use f4=f1+f2 but here f1 goes to this pointer and the input paramter is filled by f2
        int num2=(num*f.den + f.num*den); 
        int den2=f.den*den;
        fraction fnew(num2,den2);
        fnew.simplifier();
        return fnew;
    }
    
    fraction operator+(fraction f){
        int num2=(num*f.den + f.num*den); 
        int den2=f.den*den;
        fraction fnew(num2,den2);
        fnew.simplifier();
        return fnew;
    }

    fraction operator*(fraction f){
        int num2=(num*f.num); 
        int den2=f.den*den;
        fraction fnew(num2,den2);
        fnew.simplifier();
        return fnew;
    }
    
    bool operator==(fraction f){
        this->simplifier();
        f.simplifier();
        if (num==f.num && den==f.den)
        {
            return true;
        }
        else{
            return false;
        }
        
    }

    //for finding simplified form then we need greatest common divisor
    void simplifier(){
        int gcd=1;
        int j = min(num,den);
        for (int i = 1; i <= j; i++)
        {
            if (num%i==0 && den%i==0)
            {
                gcd=i;
            }
        }
        num=num/gcd;
        den=den/gcd;
    }
};

int main(){
    fraction f1(11,4),f2(7,2);
    fraction f3=f1.add2(f2);
    f3.display();
    fraction f4=f1+f2;
    f4.display();
    fraction f5=f1*f2;
    f5.display(); 
    if (f3==f4)
    {
        cout<<"equal"<<endl;
    }
    else{
        cout<<"Nhh"<<endl;
    }
    if (f1==f4)
    {
        cout<<"equal"<<endl;
    }
    else{
        cout<<"Nhh"<<endl;
    }
    return 0;}
