//? Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string. Return the sorted string. If there are multiple answers, return any of them.

//! tc : O(n k logk)
//*where n is the length of the string and k is the number of unique characters in the string
// Here, we are counting the frequency of each character in the string and then using a max heap to sort the characters based on their frequency.
//! sc : O(n + k)
//*where n is the length of the string and k is the number of unique characters in the string
// reason of sc is that we are using a map to store the frequency of each character and a max heap to store the characters based on their frequency.

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> freq;

        // couting the frequencies
        for (auto ch : s)
        {
            freq[ch]++;
        }

        // putting the char acc to freq in the max heap
        priority_queue<pair<int, char>> max_heap;

        for (auto it : freq)
        {
            max_heap.push({it.second, it.first});
        }

        // now adding the characters acc to thier freq in the resultant string
        string temp = "";
        while (!max_heap.empty())
        {
            auto [count, ch] = max_heap.top();
            max_heap.pop();
            temp += string(count, ch);
        }

        return temp;
    }
};

// basic understanding of bucket sort
🪣 Bucket Sort in Simple Terms:
Imagine sorting scores (like 0 to 100).

You create "buckets" (like boxes) for score ranges — for example, one bucket for 0–9, one for 10–19, and so on.

Put each score into the correct bucket based on its value.

Sort each bucket individually (usually with another sort like insertion sort).

Combine all buckets in order to get the final sorted list.

// optimal solution
// tc : O(n) 
// sc : O(n+k)
//reason of tc is that we are iterating through the string to count the frequency of each character, and then iterating through the frequency map to create buckets based on frequency. Finally, we iterate through the buckets to build the result string.
//reason of sc is that we are using a map to store the frequency of each character and a vector of vectors to store the characters based on their frequency. 

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> freq;
        int maxFreq = 0;

        // Step 1: Count frequency
        for (char c : s)
        {
            freq[c]++;
            maxFreq = max(maxFreq, freq[c]);
        }

        // Step 2: Bucket sort - create buckets based on frequency
        vector<vector<char>> buckets(maxFreq + 1);
        for (auto &[ch, count] : freq)
        {
            buckets[count].push_back(ch);
        }

        // Step 3: Build result string from buckets (from high freq to low)
        string result;
        for (int i = maxFreq; i >= 1; --i)
        {
            for (char ch : buckets[i])
            {
                result += string(i, ch); // repeat ch i times
            }
        }

        return result;
    }
};
