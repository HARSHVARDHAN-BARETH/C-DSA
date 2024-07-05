#include <iostream>
#include<vector>
using namespace std;

void fixArray(int arr[], int n)
{
    vector<int> vec(n, -1);
    
    for(int i=0;i<n;i++)
    {
        if(arr[i] != -1)
        {
            vec[arr[i]] = arr[i];
        }
    }
    
    for(int i=0;i<n;i++)
    {
        arr[i] = vec[i];
    }
    
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    
}

int main()
{
    int arr[] = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
    int n = sizeof(arr)/sizeof(arr[0]);
    fixArray(arr, n);

    return 0;
}