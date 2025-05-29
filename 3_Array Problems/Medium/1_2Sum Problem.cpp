//brute force approach
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

//better approach
//tc : o(nlogn) //depends on the sorting algorithm used
//sc : o(1)
//using sorting
//we sort the array and then use two pointers to find the two numbers
//but this will not give the original indices of the numbers
//so we need to store the original indices in a vector and then sort the vector
//and then use two pointers to find the two numbers's indices


//optimal solution
//tc : o(n)
//sc : o(n)
//using hash map (unordered_map)
//we used hash map to store the visited elements and their indices

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