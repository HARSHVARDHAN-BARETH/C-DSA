#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void rearange(int arr[], int n)
{
    for(int i=0;i<n;i+=2)
    {
        if(i>0 && arr[i-1] > arr[i])
        {
            int temp = arr[i-1];
            arr[i-1] = arr[i];
            arr[i] = temp;
        }
        
        if(i<n-1 && arr[i+1] > arr[i])
        {
            int temp = arr[i+1];
            arr[i+1] = arr[i];
            arr[i] = temp;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {1, 2, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    rearange(arr, n);
    
    return 0;
}