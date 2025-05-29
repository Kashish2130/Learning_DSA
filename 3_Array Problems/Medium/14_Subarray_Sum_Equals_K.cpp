//ex : 1,1,1

//ex : 1,2,3

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum = nums[i];
            for (int j = i + 1; j < n; j++) {
                sum += j;
                if (sum == k) {
                    count++;
                    continue;
                }
            }
        }

        return count;
    }
};


