#include <iostream>
using namespace std;

class heap
{
    int arr[50];
    int size;

public:
    heap();
    int getSize();
    void getinput();
    void createHeap(int);
    void heapSort(int);
    void maxHeapify(int, int);
    void displayHeap();
    void deleteRoot();
};

heap::heap(){
    cout<<"enter a size";
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
}

void heap::createHeap(int n)
{
    cout << "Building heap..." << endl;
    //build heap
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        maxHeapify(n, i);
    }

    cout << "Heap is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "-";
    }
    cout << endl;
}

void heap::maxHeapify(int n, int root)
{
    int largest = root; //initialise largest as root
    //set left and right children
    int left_child = 2 * root + 1;
    int right_child = 2 * root + 2;
    //if left_child is greater than root ,set it as new largest
    if (left_child < n && arr[left_child] > arr[largest])
    {
        largest = left_child;
    }
    //if right_child is greater than root ,set it as new largest
    if (right_child < n && arr[right_child] > arr[largest])
    {
        largest = right_child;
    }
    //if largest is not root
    if (largest != root)
    {
        //swap root and largest indexed array elements
        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;
        //recursively heapify the affected subtree
        maxHeapify(n, largest);
    }
}

void heap::heapSort(int n)
{
    //build heap
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        maxHeapify(n, i);
    }
    //one by one extract element from heap
    for (int i = n - 1; i >= 0; i--)
    {
        //swap arr0 and arri
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        cout << "The deleted element is " << temp << endl;
        //call max heapify on reduced heap
        maxHeapify(i, 0);
        cout << "Heap is:" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << "-";
        }
        cout << endl;
    }
}

void heap::getinput()
{
    cout << "Enter size of heap: " << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "-";

        cin >> arr[i];
    }
}

int main()
{
    cout<<"Enter the size of an array ?";
    int n;
    cin>>n;
    heap hp;
    hp.getinput();
    hp.createHeap(n);
    //hp.maxHeapify(n);
    hp.heapSort(n);
}