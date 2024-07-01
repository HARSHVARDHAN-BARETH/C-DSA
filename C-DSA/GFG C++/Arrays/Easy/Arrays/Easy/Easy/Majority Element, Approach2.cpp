#include <iostream>
#include<algorithm>
using namespace std;

int Majority(int arr[], int n)
{
    if(n == 0) return arr[0];
    
    sort(arr, arr+n);
    int cnt = 1;
    for(int i=1;i<n;i++)
    {
        if(arr[i-1] == arr[i])
        {
            cnt++;
        }
        else
        {
            if(cnt > n/2)
        {
            cout << arr[i-1] << " ";
        }
        cnt = 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 1, 2, 1, 3, 5, 1 };
    int n = sizeof(arr)/sizeof(arr[0]);
    Majority(arr, n);

    return 0;
}