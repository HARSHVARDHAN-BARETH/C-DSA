#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int Majority(int arr[], int n)
{
    unorderd_map<int, int> umap;
    
    for(int =0;i<n;i++)
    {
        umap[arr[i]]++;
    }
    
    int cnt = 0;
    for(auto i:umap)
    {
        if(i.second > n/2)
        {
            cnt++;
            cout << i.first << " ";
            break;
        }
    }
    
    if(cnt == 0)
    {
        cout << "No Majority Element" << endl;
    }
}

int main()
{
    int arr[] = {1, 1, 2, 1, 3, 5, 1 };
    int n = sizeof(arr)/sizeof(arr[0]);
    Majority(arr, n);
    return 0;
}