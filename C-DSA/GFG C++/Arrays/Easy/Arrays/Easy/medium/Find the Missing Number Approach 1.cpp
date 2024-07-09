#include <iostream>
using namespace std;

int missing(int arr[], int n)
{
    int sum = 0;
    for(int i=0;i<n-1;i++)
    {
        sum += arr[i];
    }
    
    int expectedSum = (n*(n+1))/2;
    return expectedSum - sum;
}

int main()
{
    int arr[] = {1,2,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << missing(arr, n);
    
    return 0;
}