#include <iostream>
#include<vector>
using namespace std;

int findMissingElement(int arr[], int n, int m)
{
    vector<int> vec(m, 0);
    for(int i=0;i<n;i++)
    {
        vec[arr[i]] = 1;
    }
    
    for(int i=0;i<n;i++)
    {
        if(vec[i] == 0) { return i; }
    }
    return -1;
}

int main()
{
   int arr[] = {0, 1, 2, 6, 9};
   int n = sizeof(arr)/sizeof(arr[0]);
   int m = 10;
   cout << findMissingElement(arr, n, m) << " ";

    return 0;
}