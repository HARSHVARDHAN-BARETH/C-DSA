#include <iostream>
using namespace std;

void FindTriplet(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(arr[i] + arr[i+1] + arr[i+2] + arr[i+3] == 0)
        {
            cout << arr[i] << " " << arr[i+1] << " " << arr[i+2] << " " << arr[i+3];
            return;
        }
    }
    
    cout << "No Triplet Found";
}

int main()
{
    int arr[] = { 0, -1, 2, -3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    FindTriplet(arr, n);

    return 0;
}