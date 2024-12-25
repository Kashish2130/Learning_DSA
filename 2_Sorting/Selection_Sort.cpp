#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionsort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int j;
        int min = i;
        for (j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

int main()
{
    int n;
    cout<<"enter the num of ele you want:";
    cin>>n;
    cout << "\n enter array elements:";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    selectionsort(arr, n);
    cout<<"\n printing the sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] <<" ";
    }
    return 0;
}