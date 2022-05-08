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
    fraction f1(10,2);
    fraction f2(15,4);
    fraction const f3(23,6);
    f3.display(); //error even at display? Why so ? Any constant object cant call any functions as compiller are worries ki hm na kre changes
//  f3.add(f2); //error must be there
    return 0;}

//but we can resolve this issue by:
//Using a constant object you can only call a contsant function and nothing else.
//How to make a constant function? 
//EG:
//void name() const{
//    return ;
//}