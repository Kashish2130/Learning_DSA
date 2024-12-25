#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"enter the size of array :";
    cin>> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // precompute
    map<int,int> mp; //if using a map // can also use unorderedmap infact PREFER using unordered map for best and averagecase since its TC is ->o(N)
    // int hash[13] = {0};
    for (int i = 0; i < n; i++)
    {
        // hash[arr[i]] += 1; 
        mp[arr[i]]++;// if using a map
    }

    //fetching
    int q;
    cin>>q;
    while(q--)
    {
        int number;
        cin>>number;
        // cout << hash[number];
        mp[number]; //if using a map
    }

}
