//tc : o(3n)
//sc : o(2n)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int sum = 0;

        vector<int> prefixMax(n);
        prefixMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(height[i], prefixMax[i - 1]);
        }

        vector<int> suffixMax(n);
        suffixMax[n - 1] = height[n - 1];
        for (int i = n - 2, i >= 0; i--) {
            suffixMax[i] = max(height[i], suffixMax[i + 1]);
        }

        for (int i = 1; i < n - 2; i++) {
            int leftmax = prefixMax[i];
            int rightmax = suffixMax[i];
            if (height[i] < leftmax && height[i] < rightMax) {
                sum = sum + (min(leftmax, rightmax) - height[i]);
            }
        }
        return sum;
    }
};

//tc : same as above
//sc : o(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> suffixMax(n);
        suffixMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(height[i], suffixMax[i + 1]);
        }

        int sum = 0;
        int leftMax = height[0];

        for (int i = 1; i < n - 1; i++) {
            leftMax = max(leftMax, height[i]);
            int water = min(leftMax, suffixMax[i]) - height[i];
            if (water > 0) sum += water;
        }

        return sum;
    }
};


//tc : o(n)
//sc : o(1)
//optimal solution
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int sum = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    sum += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    sum += rightMax - height[right];
                }
                right--;
            }
        }

        return sum;
    }
};

