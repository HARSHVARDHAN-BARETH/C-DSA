#include <iostream>
using namespace std;

void sortInWave(int arr[], int n)
{
    for(int i=0;i<n;i+=2)
    {
        if(arr[i-1]>arr[i] && i>0)
        {
            int temp = arr[i-1];
            arr[i-1] = arr[i];
            arr[i] = temp;
        }
    }
    
    for(int i=0;i<n;i+=2)
    {
        if(arr[i]<arr[i+1] && i<n-1)
        {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    
    sortInWave(arr, n);

    for(int i=0;i<n;i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}