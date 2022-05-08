#include<iostream>
using namespace std;

int multiplyNumbers(int m,int n)
{
    if (n==1)
    {
        return m;
    }
    else
    {
        int solution=m+multiplyNumbers(m,n-1);
        return solution;
    }
}

int main(){return 0;}
