#include<iostream>
using namespace std;

int tripletSum(int*arr, int n, int num)
{
    int a =0;
    // Fix the first element as A[i]
    for (int i = 0; i < n - 2; i++)
    {
 
        // Fix the second element as A[j]
        for (int j = i + 1; j < n - 1; j++)
        {
 
            // Now look for the third number
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == num)
                {
                    a++;
                }
            }
        }
    }
    return a;
}

int main(){
    int A[] = { 1, 4, 45, 6, 10, 8 };
    int sum = 22;
    int arr_size = sizeof(A) / sizeof(A[0]);
    cout<<endl<<tripletSum(A,arr_size,sum)<<endl;
    return 0;}
