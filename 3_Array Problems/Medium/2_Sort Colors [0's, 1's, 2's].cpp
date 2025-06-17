//?Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
//We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
//You must solve this problem without using the library's sort function.

//brute force
//tc : o(n^2)
//sc : o(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] > nums[j]) {
                    int temp;
                    temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }
    }
};


//better approach
//tc : o(n)
//sc : o(n) why?    
// because we are using extra space to store the count of 0's, 1's and 2's

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> v(3, 0);

        // Count occurrences
        for (auto i : nums) {
            v[i]++;
        }

        // Overwrite nums based on counts
        int index = 0;
        for (int i = 0; i < 3; i++) {
            int cnt = v[i];
            while (cnt--) {
                nums[index] = i;
                index++;
            }
        }
    }
};


//optimal approach
//DUTCH NATIONAL FLAG ALGORITHM
//we are using 3 pointers low, mid and high
//low : to keep track of the position of 0
//mid : to keep track of the position of 1
//high : to keep track of the position of 2
//we will swap the elements based on the value of mid
//if mid = 0, swap with low and increment both low and mid
//if mid = 1, increment mid
//if mid = 2, swap with high and decrement high
//we will continue this process until mid <= high
//this will ensure that all 0's are at the beginning, all 1's are in the middle and all 2's are at the end
//this is a one pass algorithm
//we are not using any extra space
//we are using constant space
//this is a linear time algorithm
//tc : o(n)
//sc : o(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
       int low = 0;
       int mid = 0;
       int high = nums.size()-1;

       while(mid <= high)
       {
            if(nums[mid] == 0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
       }
};






