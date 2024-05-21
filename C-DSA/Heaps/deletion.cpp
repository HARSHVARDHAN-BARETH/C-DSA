#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

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

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
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
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }

        // Move last element to the root
        arr[1] = arr[size];
        size--;

        // Take root node to its correct position
        int i = 1;
        while (i <= size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            int largest = i;

            if (leftIndex <= size && arr[largest] < arr[leftIndex])
            {
                largest = leftIndex;
            }
            if (rightIndex <= size && arr[largest] < arr[rightIndex])
            {
                largest = rightIndex;
            }

            if (largest != i)
            {
                swap(arr[i], arr[largest]);
                i = largest;
            }
            else
            {
                break;
            }
        }
    }
};

int main()
{
    heap h;
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(5);
    h.insert(6);
    h.insert(4);
    h.deleteFromHeap();
    h.print();

    return 0;
}
