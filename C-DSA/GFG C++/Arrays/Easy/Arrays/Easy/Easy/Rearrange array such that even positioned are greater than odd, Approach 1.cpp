#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void assign(int arr[], int n)
{
    int ptr1 = 0, ptr2 = n-1;
    int ans[n];
    sort(arr, arr+n);
    for(int i=0;i<n;i++)
    {
        if(i%2 == 0)
        {
            ans[i] = arr[ptr2--];
        }
        else
        {
            ans[i] = arr[ptr1++];
        }
    }
    
    for(int i=0;i<n;i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    int arr[] = {1,2,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    assign(arr, n);
    
    return 0;
}