//! Recursion Tree for All Permutations of a Set
// Start
// ├── [1]
// │   ├── [1, 2]
// │   │   └── [1, 2, 3]
// │   └── [1, 3]
// │       └── [1, 3, 2]
// ├── [2]
// │   ├── [2, 1]
// │   │   └── [2, 1, 3]
// │   └── [2, 3]
// │       └── [2, 3, 1]
// └── [3]
//     ├── [3, 1]
//     │   └── [3, 1, 2]
//     └── [3, 2]
//         └── [3, 2, 1]

//* Think about it like DFS traversal of a tree where each node represents a choice of the next number to add to the current permutation path. The depth of the tree corresponds to the length of the current permutation path, and the leaves of the tree represent complete permutations.
//? This code generates all permutations of a given set of numbers using backtracking.
// TODO APPROACH :1
//tc : O(n!)
//sc : O(n) + o(n)

class Solution
{
public:
    void backtrack(vector<int> &nums, vector<bool> &visited, vector<int> &path, vector<vector<int>> &result)
    {

        //! base case: if path is complete
        if (path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }

        //! recursive case: explore further
        // try all numbers
        for (int i = 0; i < nums.size(); i++)
        {
            if (!visited[i])
            {
                // choose
                visited[i] = true;
                path.push_back(nums[i]);

                // explore
                backtrack(nums, visited, path, result);

                // un-choose (backtrack)
                path.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> visited(nums.size(), false);

        backtrack(nums, visited, path, result);

        return result;
    }
};

// TODO: APPROACH :2
//tc : O(n!)*o(n)
//sc : O(n)

#include <vector>
#include <algorithm>

class Solution
{
public:
    void backtrack(std::vector<int> &nums, std::vector<std::vector<int>> &result, int index)
    {

        //! base case: if path is complete
        if (index == nums.size() - 1)
        {
            result.push_back(nums);
            return;
        }

        //! recursive case: explore further
        // try all numbers
        for (int i = index; i < nums.size(); i++)
        {
            std::swap(nums[index], nums[i]);
            backtrack(nums, result, index + 1);
            std::swap(nums[index], nums[i]);
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> result;
        int index = 0;

        backtrack(nums, result, index);

        return result;
    }
};
