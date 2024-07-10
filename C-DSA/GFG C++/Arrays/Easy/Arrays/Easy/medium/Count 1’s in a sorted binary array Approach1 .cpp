#include <iostream>
using namespace std;


void Binary(int arr[], int n)
{
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] == 1)
        {
            count++;
        }
    }
    
    cout << count;
}

int main()
{
    int arr[] = {1, 1, 0, 0, 1, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    Binary(arr, n);

    return 0;
}