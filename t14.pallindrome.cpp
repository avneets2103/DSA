//Check if the number is a pallindrome or not
#include<iostream>
using namespace std;

int arraySize(char array[])
{
    int cont = 0;
    for (int i = 0; array[i] != 0; i++)
            cont++;
    return cont;
}

bool checkPalindromeh(char input[],int size){
    static int a = 0;
    //base
    if (size-a<0)
    {
        return true;        
    }
    //induction
    if (input[0]!=input[size-1-a])
    {
        return false;
    }
    else{
        a++;
        if (checkPalindromeh(input+1,size-1))
        {
            return true;
        }
        else{
            return false;
        }
    }
}

bool checkPalindrome(char input[]) {
    int size= arraySize(input);
    return checkPalindromeh(input,size);
}

int main(){
    char m[100];
    cout<<"Enter m: "<<endl;
    cin>>m;
    cout<<checkPalindrome(m);
    return 0;}

