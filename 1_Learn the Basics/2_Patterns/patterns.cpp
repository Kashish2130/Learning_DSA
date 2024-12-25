#include <bits/stdc++.h> //includes all the libraries
using namespace std;

// void pattern1(int n)
// {
//     for (int row = 0; row < n; row++)
//     {
//         for (int col = 0; col < n; col++)
//         {
//             cout << "*";
//         }
//         cout << "\n";
//     }
// }

// void pattern2(int n)
// {
//     for (int row = 0; row < n; row++)
//     {
//         for (int col = 0; col <= row; col++)
//         {
//             cout << "*";
//         }
//         cout << "\n";
//     }
// }

// void pattern3(int n)
// {
//     for (int row = 0; row < n; row++)
//     {
//         for (int col = 0; col <= row; col++)
//         {
//             cout << col + 1;
//         }
//         cout << "\n";
//     }
// }

// void pattern4(int n)
// {
//     for (int row = 0; row < n; row++)
//     {
//         for (int col = 0; col <= row; col++)
//         {
//             cout << row + 1;
//         }
//         cout << "\n";
//     }
// }

// void pattern5(int n)
// {
//     for (int row = 0; row < n; row++)
//     {
//         for (int col = n - 1; col >= row; col--)
//         {
//             cout << "*";
//         }
//         cout << "\n";
//     }
// }

// void pattern6(int n)
// {
//     for (int row = n; row >= 0; row--)
//     {
//         for (int col = 0; col < row; col++)
//         {
//             cout << col + 1;
//         }
//         cout << "\n";
//     }
// }

// void pattern7(int n)
// {
//     for (int row = 0; row <= n; row++)
//     {
//         for (int col = 0; col <= (row + n); col++)
//         {
//             if (col >= (n - row))
//             {
//                 cout << "*";
//             }
//             else
//             {
//                 cout << " ";
//             }
//         }
//      cout<<"\n";
//     }
// }

// void pattern8(int n)
// {
//     for(int row=1;row<=n;row++)
//     {
//         for(int col=(2*n-1);col>=row;col--)
//         {
//             if(col<=(2*n-row))
//             {
//                 cout<<"*";
//             }
//             else{
//                 cout<<" ";
//             }
//         }
//         cout<<"\n";
//     }
// }

void pattern9(int n)
{
    for(int row=0;row<=n;row++)
    {
        for(int col=0;col<=n-1;col++)
        {
            
        }
    }
}

int main()
{
    int num;
    cout << "enter the no:";
    cin >> num;
    // pattern1(num);
    // pattern2(num);
    // pattern3(num);
    // pattern4(num);
    // pattern5(num);
    // pattern6(num);
    // pattern7(num);
    // pattern8(num);
    pattern9(num);
}
