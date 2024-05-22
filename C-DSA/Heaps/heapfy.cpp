#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class heap
{
    public:
    int arr[100];
    int size = 0;
    
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        
        while(index > 1)
        {
            int parent = index/2;
            
            if(arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    
    void print()
    {
        for(int i=1;i<=size;i++)
        {
            cout << arr[i] << " ";
        }cout << endl;
    }
};

void hepfy(int arr[], int n, int i)
{
    int largest = i;
    int left = i*2;
    int right = i*2 + 1;
    
    if(left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if(right < n && arr[largest] < arr[right])
    {
        largest = right;
    }
    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        hepfy(arr, n, largest);
    }
}

int main()
{
    heap h;
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(5);
    h.insert(6);
    h.insert(4);
    h.print();
    
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i=n/2;i>0;i--)
    {
        hepfy(arr, n, i);
    }
    cout << "Printing the array now " << endl;
    for(int i=1;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}