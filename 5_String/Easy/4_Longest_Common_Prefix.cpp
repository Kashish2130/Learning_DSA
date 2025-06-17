//?Write a function to find the longest common prefix string amongst an array of strings.

//If there is no common prefix, return an empty string "".

//brute force
//tc : O(n*m) where n is the number of strings and m is the length of the longest string
//sc:  O(1) since we are using a constant amount of space for the prefix string

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for (int i = 0; i < strs[0].size(); i++) {
            char ch = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i > strs[j].length() || strs[j][i] != ch) {
                    return prefix;
                }
            }
            prefix += ch;
        }
        return prefix;
    }
};

//optimal approach
//tc : O(nlogn) where n is the number of strings
//sc: O(1) since we are using a constant amount of space for the prefix string

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) {
            return "";
        }

        sort(strs.begin(), strs.end());
        string first = strs.front();
        string last = strs.back();
        int i = 0;

        while (i < first.length() && i < last.length() && first[i] == last[i]) {
            i++;
        }

        return first.substr(0, i);
    }
};

//! reason behind the optimal approach:
//1. Sorting the strings ensures that the first and last strings in the sorted order will have the longest common prefix. (remeber sorting is done in lexicographical order which means dictionary order)
//2. The common prefix of the first and last strings will be the longest common prefix of all strings in the array.
//3. The time complexity is O(n log n) due to the sorting step, and the space complexity is O(1) since we are not using any additional data structures that grow with input size.
// This approach is efficient and works well for finding the longest common prefix in a set of strings.
// Note: The optimal approach assumes that the input strings are not empty. If the input can contain empty strings, additional checks may be needed.
