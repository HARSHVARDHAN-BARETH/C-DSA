#include <iostream>
using namespace std;

int subArray(int arr[], int n, int k)
{
    int start = 0, end = 0;
    int sum = 0;
    
    while(end < n)
    {
        sum += arr[end];
        
        while(sum > k && start < end)
        {
            sum -= arr[start++];
        }
        
        if(sum == k)
        {
            cout << "Found at " << start << endl;
            return 1;
        }
        
        end++;
    }
    
    cout << "No subArray Found " << endl;
    return 0;
    
}

int main()
{
   int arr[] = { 15, 2, 4, 8, 9, 5, 10, 23 };
   int n = sizeof(arr)/sizeof(arr[0]);
   int sum = 23;
   subArray(arr, n, sum);

    return 0;
}