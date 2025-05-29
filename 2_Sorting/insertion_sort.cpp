#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void insertion_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}

int main()
{
    int n;
    cout << "enter the num of ele you want:";
    cin >> n;
    cout << "\n enter array elements:";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    insertion_sort(arr, n);
    cout << "\n printing the sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}


//ANOTHER LOGIC FOR INSERTION SORT (i remember this because this is easy to create on your own)
#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &v, int size)
{

    int j;
    for (int i = 1; i < size; i++)
    {
        int key = v[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (key >= v[j])
            {
                break;
            }

            v[j + 1] = v[j];
        }

        v[j + 1] = key;
    }
}

int main()
{
    vector<int> v = {31, 9, 42, 71, 16};
    insertion_sort(v, v.size());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}