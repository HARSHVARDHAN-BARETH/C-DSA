#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printDuplicate(int arr[], int n)
{
    unordered_set<int> inset;
    unordered_set<int> duplicate;
    
    for(int i=0;i<n;i++)
    {
        if(inset.find(arr[i]) == inset.end())
        {
            inset.insert(arr[i]);
        }
        else
        {
            duplicate.insert(arr[i]);
        }
    }
    
    for(auto it=duplicate.begin(); it!=duplicate.end();it++)
    {
        cout << (*it) << " ";
    }
}

int main()
{
    int arr[] = { 1, 5, 2, 1, 4, 3, 1, 7, 2, 8, 9, 5 };
    int n = sizeof(arr) / sizeof(int);
    printDuplicate(arr, n);
    
    return 0;
}