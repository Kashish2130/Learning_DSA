#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout<<"enter string:";
    cin>>s;

    //precompte
    int hash[26] ={0};//using hash array
    //map<char,int> mp;
    //i can also take array of 256 characters thnen we do not have to do - 'a' anywhere
    for(int i= 0;i<s.size();i++)
    {
        hash[s[i] - 'a']++;
        //mp[s[i]]++; if using a map
        
    }

    //fetching
    int q;
    cout<<"enter the number of queries: ";
    cin>>q;
    while(q--)
    {
        char c;
        cin>>c;
        cout<<hash[c - 'a']<<endl;
        //mp[c];
    }

    return 0;

}

//using maps

