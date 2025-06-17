//? Given two strings s and t, return true if t is an anagram of s, and false otherwise.

//brute force
//sorting approach
//tc: O(nlogn)
//sc: O(1)

class Solution {
public:
    bool isAnagram(string s, string t) { 
        if(s.length() != t.length())
        {
            return false;
        }

        sort(s.begin(), s.end()); 
        sort(t.begin(),t.end());

        if (s == t)
        {
            return true;
        }

        return false;
    }
};

//better approach
//using unordered_map
//tc: O(n)
//sc: O(n)

#include <unordered_map>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        for (char c : t) {
            if (freq.find(c) == freq.end() || freq[c] == 0) return false;
            freq[c]--;
        }

        return true;
    }
};

//optimal approach
//using frequency array
//tc: O(n)
//sc: O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        int freq[26] = {0};

        for (char c : s) {
            freq[c - 'a']++;
        }

        for (char c : t) {
            freq[c - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) return false;
        }

        return true;
    }
};


