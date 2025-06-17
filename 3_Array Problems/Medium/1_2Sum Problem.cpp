//?Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.


//!brute force approach
//tc : o(n^2)
//sc : o(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum;
        int n = nums.size();
        // vector<int> temp;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                sum = 0;
                sum = nums[i] + nums[j];
                if (sum == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

//!better approach
//tc : o(nlogn) //depends on the sorting algorithm used
//sc : o(1)
//using sorting
//we sort the array and then use two pointers to find the two numbers
//but this will not give the original indices of the numbers
//so we need to store the original indices in a vector and then sort the vector
//and then use two pointers to find the two numbers's indices

//*working of this approach*
//how this works:
//1. Sort the array and store the original indices in a vector.
//2. Use two pointers to find the two numbers that add up to the target.
//how to use two pointers:
//1. Initialize two pointers, one at the beginning and one at the end of the array.
//2. If the sum of the two numbers is equal to the target, return the indices.  
//3. If the sum is less than the target, move the left pointer to the right.
//4. If the sum is greater than the target, move the right pointer to the left.



//!optimal solution
//tc : o(n)
//sc : o(n)
//using hash map (unordered_map)
//we used hash map to store the visited elements and their indices

//*how this works*:
//1. Use a hash map to store the visited elements and their indices.
//2. For each element in the array, calculate the remaining amount (target - current element).
//3. If the remaining amount is present in the hash map, return the indices of the current element and the remaining amount.    
//4. If the remaining amount is not present in the hash map, add the current element and its index to the hash map.
//5. Continue until a solution is found or the end of the array is reached.
// Note: This approach does not require sorting the array, so it is more efficient than the previous approach.

//give one example to understand the working of this approach:
// Example: nums = [2, 7, 11, 15], target = 9
// 1. Initialize an empty hash map.
// 2. Iterate through the array:
//    - For i = 0, nums[0] = 2, remaining amount = 9 - 2 = 7. Not in hash map, add {2: 0}.
//    - For i = 1, nums[1] = 7, remaining amount = 9 - 7 = 2. Found in hash map, return {0, 1}.
// 3. The function returns the indices of the two numbers that add up to the target.


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // remAmt = remaining amount
        unordered_map<int, int> visited;
        for (int i = 0; i < nums.size(); i++) {
            int remAmt;
            remAmt = target - nums[i];
            if (visited.count(remAmt)) {
                return {visited[remAmt], i};
            }
            visited[nums[i]] = i;
        }
        return {};
    }
};