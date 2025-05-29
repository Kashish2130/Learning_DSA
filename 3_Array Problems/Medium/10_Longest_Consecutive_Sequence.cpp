//brute force solution
//tc : O(n^2)
//sc : O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0; // Handle empty input case
        int maxlen = 1; // Start with 1 since a single number is a sequence
        
        for (int i = 0; i < nums.size(); i++) {
            int count = 1; // Start counting from the current number
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == nums[i] + count) {
                    count++;
                }
            }
            maxlen = max(maxlen, count); // Update maximum length found
        }
        
        return maxlen; // Return the maximum length found
    }
};

// better solution
//tc : O(n log n)
//sc : O(1) 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0; // Handle empty input case
        sort(nums.begin(), nums.end());
        int maxlen = 1; // Start with 1 since a single number is a sequence
        int count = 1; // Start with the first element
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) continue; // Skip duplicates
            if (nums[i] - nums[i - 1] == 1) {
                count++;
                maxlen = max(maxlen, count);
            } else {
                count = 1; // Reset for a new sequence
            }
        }
        
        return maxlen; // Return the maximum length found
    }
};

//? is the above logic called as "Two Pointers Technique"?
// No, the above logic is not typically referred to as the "Two Pointers Technique."
// It is more of a single pass through the sorted array with a counter to track the length of consecutive sequences.
// The "Two Pointers Technique" usually involves maintaining //* two indices to explore different parts of a data structure, often used in problems like finding pairs or subarrays.
// The above code is a straightforward approach to finding the longest consecutive sequence in an array of integers.

// The time complexity of the above code is  : //! O(n log n) 
// due to the sorting step, where n is the number of elements in the input vector.
// The space complexity is : //! O(1)
//if we ignore the input storage, as we are using a constant amount of extra space for variables. 

//optimal solution
// tc : O(n)
// sc : O(n)


//ex : 102,4,100,1,101,3,2
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end()); // Store all numbers in a set for O(1) lookups
        int maxlen = 0; // Initialize maximum length
        
        for (int num : nums) {
            if (numSet.find(num) == numSet.end()) continue; // Skip if the number is already processed

            numSet.erase(num); // Remove the number to avoid reprocessing
            
            int count = 1; // Start counting from the current number
            
            // Count upwards
            int nextNum = num + 1;
            while (numSet.find(nextNum) != numSet.end()) {
                numSet.erase(nextNum);
                count++;
                nextNum++;
            }
            
            // Count downwards
            int prevNum = num - 1;
            while (numSet.find(prevNum) != numSet.end()) {
                numSet.erase(prevNum);
                count++;
                prevNum--;
            }
            
            maxlen = max(maxlen, count); // Update maximum length found
        }
        
        return maxlen; // Return the maximum length found
    }
};


//*🧪 DRY RUN (with comments):
// We also maintain maxlen = 0.

//! 🔁 First: num = 102
// Is 102 in numSet? ✅ Yes
// Erase 102
// Try to expand upward → 103 ❌ not in set
// Try to expand downward → 101 ✅ erase, count++
// 100 ✅ erase, count++
// 99 ❌ stop
// ✅ Sequence: [100, 101, 102]
// 🧮 count = 3 → maxlen = 3

//? Now, numSet = {1, 2, 3, 4}


//! 🔁 Next: num = 4
// 4 in numSet? ✅
// Erase 4
// Upward: 5 ❌
// Downward: 3 ✅ erase
// 2 ✅ erase
// 1 ✅ erase
// 0 ❌
// ✅ Sequence: [1, 2, 3, 4]
// 🧮 count = 4 → maxlen = 4

//? Now numSet = {} (all numbers processed)

//TODO: 🔁 Remaining numbers:
// The rest of the nums array is [100, 1, 101, 3, 2], but all of these have been removed from the set already, so the loop skips them.

//* 🎯 Final Answer:
// maxlen = 4

// 🧠 Summary of Logic:
// Use a set for fast lookup.

// For each number, try to expand both up and down.

// Remove numbers as you process them, so you don't repeat work.

// Track the maximum length.

// ✅ Time & Space Complexity
// Time: O(n)
// Each number is processed only once.

// Space: O(n)
// For storing elements in the unordered set.
