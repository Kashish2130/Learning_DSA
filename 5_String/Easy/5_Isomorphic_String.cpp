//?Given two strings s and t, determine if they are isomorphic.

//Two strings s and t are isomorphic if the characters in s can be replaced to get t.

//All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

//optimal solution
//tc: o(n)
//sc: o(1)

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, char> sTOt;
        unordered_map<char, char> tTOs;

        for (int i = 0; i < s.length(); i++) {
            char fromS = s[i];
            char toT = t[i];

            if (sTOt.count(fromS)) {
                if (sTOt[fromS] != toT) {
                    return false;
                }
            } else {
                sTOt[fromS] = toT;
            }

            if (tTOs.count(toT)) {
                if (tTOs[toT] != fromS) {
                    return false;
                }
            } else {
                tTOs[toT] = fromS;
            }
        }

        return true;
    }
};

//! explanation of above code:
//1. We first check if the lengths of the two strings are equal. If not, they cannot be isomorphic. 
//2. We use two hash maps: one to map characters from `s` to `t` and another to map characters from `t` to `s`.
//3. We iterate through each character in the strings:
//   - If the character from `s` has already been mapped to a character in `t`, we check if it matches the current character in `t`.
//   - If it does not match, we return false.
//   - If it has not been mapped yet, we create a new mapping.
//   - We do the same for the character from `t` to `s`.
//4. If we complete the loop without finding any mismatches, we return true, indicating that the strings are isomorphic.
