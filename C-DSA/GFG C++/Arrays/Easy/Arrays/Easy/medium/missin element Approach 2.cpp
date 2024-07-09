#include <iostream>
using namespace std;

int missing(int arr[], int n)
{
    int xor1 = 0, xor2 = 0;
    for(int i=0;i<n-1;i++)
    {
        xor2^=arr[i];
    }
    
    for(int i=1;i<=n;i++)
    {
       xor1^=i;
    }
    
    return xor1^xor2;
}

int main()
{
    int arr[] = {1,2,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int miss = missing(arr, n);
    cout << miss;
    
    return 0;
}