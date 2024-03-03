#include <iostream>
#include <cmath> // Use <cmath> instead of <math.h> for C++
using namespace std;

#define MAX 1000

// Declare HashTable as a global 2D array
bool HashTable[MAX+1][2] = {false}; // Initialize all elements to false

bool Search(int x)
{
    if(x >= 0)
    {
        if(HashTable[x][0] == 1) // Checks if positive number is present
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        x = abs(x); // Use abs(x) instead of abc(x)
        if(HashTable[x][1] == 1) // Checks if negative number is present
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void insert(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i] >= 0)
        {
            HashTable[a[i]][0] = 1; // Mark the presence of positive numbers
        }
        else
        {
            HashTable[abs(a[i])][1] = 1; // Correctly mark the presence of negative numbers in the second column
        }
    }
}

int main()
{
    int arr[] = {-1, 9, 2, -5, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    insert(arr, n);
    
    int find = 9;
    if(Search(find))
    {
        cout << "Element is present" << endl;
    }
    else
    {
        cout << "Element is not present" << endl;
    }

    return 0;
}
