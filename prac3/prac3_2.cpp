#include <iostream>
using namespace std;
   
#include <bits/stdc++.h>
using namespace std;
 
void sortColors(vector<int>& arr) {
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;

    while (mid <= high) {

        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }

        else if (arr[mid] == 1) {
            mid++;
        }

        else { 
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}


int main()
{
    int n;
    cout << "Enter number of buckets: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter colour codes (0,1,2):\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int count0 = 0, count1 = 0, count2 = 0;

   
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
            count0++;
        else if(arr[i] == 1)
            count1++;
        else
            count2++;
    }

    //  Overwrite
    int index = 0;

    while(count0--)
        arr[index++] = 0;

    while(count1--)
        arr[index++] = 1;

    while(count2--)
        arr[index++] = 2;

    cout << "Sorted colours: ";

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}