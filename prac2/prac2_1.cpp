#include <bits/stdc++.h>
using namespace std;

// Normal (iterative) linear search
int linearsearch(string arr[], int n, string target)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

// Recursive linear search
int recursiveSearch(string arr[], int n, int index, string target)
{
    if(index == n) return -1;
    if(arr[index] == target) return index;

    return recursiveSearch(arr, n, index + 1, target);
}

int main()
{
    string plates[] = {"GJ01AB1234", "GJ05XY5678", "MH12CD9876", "RJ14PQ1111"};
    int n = 4;

    string target = "MH12CD9876";

    int ans1 = linearsearch(plates, n, target);
    int ans2 = recursiveSearch(plates, n, 0, target);

    cout << "normal linear search:" << endl;
    if(ans1 != -1)
    {
        cout << "Number plate found: " << target << " at index " << ans1 << endl;
    }
    else
    {
        cout << "Number plate not found." << endl;
    }

    cout << endl;

    cout << "recursive linear search:" << endl;
    if(ans2 != -1)
    {
        cout << "Number plate found: " << target << " at index " << ans2 << endl;
    }
    else
    {
        cout << "Number plate not found." << endl;
    }

    return 0;
}
