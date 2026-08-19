#include <iostream>
using namespace std;

// Bubble Sort
void bubbleSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minIndex=i;

        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minIndex])
                minIndex=j;
        }

        swap(arr[i],arr[minIndex]);
    }
}

// Insertion Sort
void insertionSort(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;

        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=key;
    }
}

void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int n;

    cout<<"Enter number of marks: ";
    cin>>n;

    int arr[n];

    cout<<"Enter marks:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int bubble[n], selection[n], insertion[n];

    for(int i=0;i<n;i++)
    {
        bubble[i]=arr[i];
        selection[i]=arr[i];
        insertion[i]=arr[i];
    }

    bubbleSort(bubble,n);
    cout<<"\nBubble Sort: ";
    printArray(bubble,n);

    selectionSort(selection,n);
    cout<<"Selection Sort: ";
    printArray(selection,n);

    insertionSort(insertion,n);
    cout<<"Insertion Sort: ";
    printArray(insertion,n);

    return 0;
}