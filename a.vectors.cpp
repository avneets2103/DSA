/*
Vectors are dynamic arrays, which are just inbuilt
Vector is an inbuilt set template based class and 
*/
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    cout<<v[0]<<endl;
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;
    v[3]=123; //not the best way, may or maynt work
    // as pushback is a function in the class which actuallys checks if the size<req or not, and does the action.
    // we will only use v[i] for get and update of values only, cant insert using this.
    //similar to this we have v.pop_back() to pop out the last element 
    
    cout<<v.at(2)<<endl;
    cout<<v.at(5)<<endl;
    //v.at(i) is a function for vector used to print the elements the i'th index and gives an error if i>=size
    //thus v.at() is safer

    //for printing all elements
    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<endl;
    }

    //capacity is also a function which tells the current capacity of the array being used 
    //using v.capacity()

    return 0;
}

