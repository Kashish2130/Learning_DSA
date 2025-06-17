//? The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
//For example, the beauty of "abaacc" is 3 - 1 = 2. Given a string s, return the sum of beauty of all of its substrings.


// 🧠 Time Complexity:
// Outer loop: O(n)

// Inner loop: O(n)

// Frequency check (fixed 26 chars): O(1)

//tc : O(n^2) and 0(n^3)-> worst case
// sc : O(1)

class Solution
{
public:
    int beautySum(string s)
    {
        int n = s.size();
        int totalBeauty = 0;


        //this for loop iterates over all starting indices of substrings
        for (int i = 0; i < n; i++)
        {
            int freq[26] = {0};

            //this for loop iterates over all ending indices of substrings starting from index i
            //it calculates the frequency of characters in the substring s[i..j]

            for (int j = i; j < n; j++)
            {
                freq[s[j] - 'a']++;

                int maxFreq = 0;
                int minFreq = INT_MAX;

                //this for loop calculates the maximum and minimum frequency of characters in the current substring
                for (int k = 0; k < 26; k++)
                {
                    if (freq[k] > 0)
                    {
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }

                totalBeauty += (maxFreq - minFreq);
            }
        }

        return totalBeauty;
    }
};

//but i have a question where are we forming the substrings here?
// The substrings are formed implicitly by the nested loops. The outer loop iterates over all possible starting indices of the substrings (i), and the inner loop iterates over all possible ending indices (j) starting from i. The substring is defined as s[i..j], which is the portion of the string from index i to index j, inclusive.


//! also can you explain the logic of the code?
// The logic of the code is to calculate the beauty of all possible substrings of the given string `s`. The beauty of a substring is defined as the difference between the maximum frequency and minimum frequency of characters in that substring. Here's a breakdown of how the code works:
// 1. The outer loop iterates over all possible starting indices of the substrings (i).
// 2. The inner loop iterates over all possible ending indices (j) starting from the current index i.
// 3. For each substring defined by the indices i and j, the frequency of each character is updated in the `freq` array.
// 4. After updating the frequency for the current substring, the code calculates the maximum and minimum frequencies of characters that appear in the substring.   
// 5. The beauty of the current substring is calculated as the difference between the maximum and minimum frequencies, and this value is added to the total beauty.
// 6. Finally, the total beauty of all substrings is returned.


//so basically we are not storing the substrings instead we just keeping the frequency of characters in the substring and calculating the beauty on the fly.
// This approach avoids the need to explicitly store all substrings, which would be inefficient in terms of both time and space complexity.
// The time complexity of this code is O(n^3) in the worst case because of the three nested loops:
// 1. The outer loop runs n times (for each starting index i).
// 2. The middle loop runs up to n times (for each ending index j starting from i).
// 3. The inner loop runs a constant number of times (26) to calculate the maximum and minimum frequencies.
// The space complexity is O(1) because the `freq` array has a fixed size of 26, regardless of the input string length.

