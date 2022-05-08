/*
Post increament overloading
f++

[NOTE: post inc. pe nesting isnt allowed]
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

    fraction operator++(int){
        fraction fnew(num,den);
        fnew.simplifier();
        num=num+den;
        simplifier();
        return fnew;
    }

    //but for nesting we need to return a value
    fraction& operator+=(fraction const &f2){ 
        fraction fNew(num,den);
        num=num*f2.den+f2.num*den;
        den=den*f2.den;
        simplifier();
        return *this;
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
    fraction f1(10,2),f2(15,4);
    fraction f3=f1++;
    f3.display();
    f3+=f2;
    f3.display();

    return 0;}
