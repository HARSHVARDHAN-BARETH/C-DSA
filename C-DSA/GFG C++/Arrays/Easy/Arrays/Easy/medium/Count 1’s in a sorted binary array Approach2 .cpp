#include <iostream>
using namespace std;


int Binary(int arr[], int n)
{
    
    int low = 0, high = n-1;
    
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(arr[mid] < 1)
        {
            high = mid-1;
        }
        else if(arr[mid] > 1)
        {
            low = mid + 1;
        }
        
        else
        {
            if(mid == n-1 || arr[mid+1] != 1)
            {
                return mid+1;
            }else{
                low = mid + 1;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = { 1, 1, 1, 1, 0, 0, 0 };
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int result = Binary(arr, n);
    
     if (result != -1)
     {
         cout << result;
     }
     else
     {
         cout << "Not Found";
     }

    return 0;
}