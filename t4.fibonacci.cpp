//f(n)=f(n-1)+f(n-2)
#include<iostream>
using namespace std;

int fibonacci(int n)
{
    if (n==1)
    {
        return 0;
    }
    else if(n==2)
    {
        return 1;
    }
    else
    {
        int solution = fibonacci(n-1)+fibonacci(n-2);
        return solution;
    }
}

int main()
{
    cout<<"You want fibonacci till what element? :"<<endl;
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cout<<fibonacci(i)<<" ";
    }
    return 0;
 }
