#include<iostream>
using namespace std;

int main()
{
    int a[5] = {1,2,3,3,5};
    int n = 5;

    for(int i = 0; i < n; i++)
    {
        bool printed = false;

     
        for(int k = 0; k < i; k++)
        {
            if(a[i] == a[k])
            {
                printed = true;
                break;
            }
        }

        if(printed)
            continue;

        for(int j = i + 1; j < n; j++)
        {
            if(a[i] == a[j])
            {
                cout << "Duplicate Book ID: " << a[i] << endl;
                break;
            }
        }
    }

    return 0;
}