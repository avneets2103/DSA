//Dynamic array class
//We keep adding until size gets small, then we double it and add till it gets small and then double again and so on.
//Note: We make a new array everytime we double and copy old array into the new one.

#include<iostream>
using namespace std;

class dynamic_array{
    int *data;
    int nextI;
    int capacity; //total size at a point

    public:
    dynamic_array(){
        data = new int[5];
        nextI=0;
        capacity=5;}

    dynamic_array(dynamic_array const &d){  //copy constructor
        this->data=new int[d.capacity];
        for (int i = 0; i < d.nextI; i++)
        {
            this->data[i]=d.data[i];
        }
        this->data=d.data;
        this->nextI=d.nextI;
    }
    
    void operator=(dynamic_array const&d){  //copy assignment operator
        this->data=new int[d.capacity];
        for (int i = 0; i < d.nextI; i++)
        {
            this->data[i]=d.data[i];
        }
        this->data=d.data;
        this->nextI=d.nextI;
    }

    void add(int element){
        if (nextI==capacity)//condition for mkaing a new one
        {
            int *newdata=new int[2*capacity]; //new array in making
            for(int i=0;i<capacity;i++){ //creating a copy
                newdata[i]=data[i];
            }
            delete [] data; //deallocate old memory
            data=newdata; //copy assignment operator
            capacity=capacity*2;
        };
        data[nextI]=element;
        nextI++;   
    }

    int get(int i){
        if(i<nextI){
            return data[i];
        }
        else{
            return -1;
        }
    }

    void add(int i,int element){
       if(i<nextI){
           data[i]=element;
       } 
       else if(i==nextI){
           add(element);
       }
       else{
           return;
       }
    }

    void print(){
        for (int i = 0; i < nextI; i++)
        {
            cout<<data[i]<<" ";
        }
    }
};

int main(){
    dynamic_array d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);
    d1.print();
    cout<<endl;
    dynamic_array d2(d1); //shallow copy krdi mc ne
    d1.add(0,100);
    d2.print();
    return 0;}
