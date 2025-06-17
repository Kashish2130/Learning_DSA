//? Given a string, find the number of substrings that can be formed from it.


//tc of above code is O(n) because we are just calculating the length of the string and performing a constant time arithmetic operation.
// sc is O(1) because we are using a constant amount of space for the calculation.

#include <iostream>
#include <string>
using namespace std;
int countSubstrings(const string& str) {
    int n = str.length();
    // The number of substrings of a string of length n is given by the formula n * (n + 1) / 2
    return n * (n + 1) / 2;
}   



//tc: // O(n^2) for the nested loop approach
// sc: O(1) for the constant space used in the calculation

//other approach
int countSubstrings2(const string& str) {
    int count = 0;
    int n = str.length();
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            count++;
        }
    }
    return count;
}



