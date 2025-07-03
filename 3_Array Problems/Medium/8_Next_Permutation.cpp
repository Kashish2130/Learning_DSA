//TODO: go through all permutations first and then find the next permutation
//* optimal approach
//tc: O(3n)
//sc: O(1)

//for revision - refer video!!

#include <vector>
#include <algorithm>

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();

        //* finding the break point  =  longest prefix match
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        //* if the longest prefix is the whole array, then reverse the whole array
        //* and that is the next permutation
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }


        //* finding the next greater element from the right side of the break point
        //* and swapping it with the break point
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }
        //for ex : 2|1|7|3|4|0|0| is the array
        //now tell 1 will be swapped with 4 or 3 and how?
        //but according to the above logic dont you think any numbr gretaer than 1 would be swpped but not just the closest one

        //* reversing the suffix after the break point to get the next permutation
        //* this is done to get the smallest permutation after the break point
        //* since the suffix is in descending order, reversing it will give us the smallest permutation
        //* this is the next permutation
        reverse(nums.begin() + index + 1, nums.end());
    }
};