
// C++ program for implementation of Heap Sort
#include <iostream>

using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;   
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    
    if (l < n && arr[l] > arr[largest])
        largest = l;

    
    if (r < n && arr[r] > arr[largest])
        largest = r;

    
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
    
}


void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

int main()
{
    cout<<"Enter the size of an array :";
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cout<<"Enter the element "<<i+1<<" :";
        cin>>arr[i];
    }

    int n = size;

    heapSort(arr, n);

    cout << "\n Heap Sorted array is \n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << "-";
    cout << "\n";
}
/*
Enter the size of an array :5
Enter the element 1 :10
Enter the element 2 :80
Enter the element 3 :50
Enter the element 4 :60
Enter the element 5 :70

 Heap Sorted array is
10-50-60-70-80-
*/