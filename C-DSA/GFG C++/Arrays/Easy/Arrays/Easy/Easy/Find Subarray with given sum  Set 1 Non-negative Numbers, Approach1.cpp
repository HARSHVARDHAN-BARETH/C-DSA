#include <iostream>
using namespace std;

void subArray(int arr[], int n, int sum)
{
    for(int i=0;i<n;i++)
    {
        int currSum = arr[i];
        if(currSum == sum)
        {
            cout << "Indexing of subArray " << i << " ";
            return;
        }
        else
        {
            for(int j=i+1;j<n;j++)
            {
                int currSum = currSum + arr[j];
                if(currSum == sum)
                {
                    cout << "Sum found between indexing " << i << " " << j << " ";
                    return;
                }
            }
        }
    }
    
    cout << "No SubArray Found";
    
}

int main()
{
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 23;
    subArray(arr, n, sum);

    return 0;
}