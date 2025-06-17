//my own solution
//tc : O(n)
//sc : O(n)

class Solution {
public:
    string reverseWords(string s) {
        string ans;
        vector<string> temp;
        string word = "";
        int m = s.length();

        for (int ch = 0; ch < m; ch++) {
            if (s[ch] == ' ') {
                if (!word.empty()) {
                    temp.push_back(word);
                    word = "";
                }
            } else {
                word += s[ch];
            }
        }

        if (!word.empty()) {
            temp.push_back(word);
        }

        int n = temp.size();
        for (int i = n - 1; i >= 0; i--) {
            ans += temp[i];
            if (i != 0)
                ans += " ";
        }

        return ans;
    }
};

//ideal solution
//tc: O(n)
//sc: O(n)

#include <bits/stdc++.h>
using namespace std;

int main() {
    string input = "Hello this is a sample string";
    vector<string> words;

    stringstream ss(input); //ss contains the input string which you can extract words from
    // Using stringstream to split the string into words excluding spaces
    // This is a more efficient way to handle string splitting in C++
    string word;

    while (ss >> word) {
        words.push_back(word);
    }

    // Output the words
    for (const auto& w : words) {
        cout << w << endl;
    }

    return 0;
}
