#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[j], arr[low]);
    return j;
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int PI = partition(arr, low, high);
        quick_sort(arr, low, PI - 1);
        quick_sort(arr, PI + 1, high);
    }
}

int main()
{
    int n;
    cout << "enter the num of ele you want:";
    cin >> n;
    cout << "\n enter array elements: ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quick_sort(arr, 0, n - 1);
    cout << "\n printing the sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}