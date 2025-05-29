// this is a classic Next Greater Element problem that is efficiently solved using a monotonic stack.

// monotonic stack is a stack that maintains elements in either increasing or decreasing order. It is used to efficiently solve problems related to Next Greater Element (NGE), Next Smaller Element (NSE), Nearest Greater/Smaller Element, Histogram problems, etc.

//  Monotonic Increasing Stack 
// A monotonic increasing stack maintains elements in increasing order (from bottom to top).
// This means:

// The top of the stack always has the smallest element.
// When pushing a new element, pop elements from the stack if they are greater than or equal to the current element.

// Monotonic Decreasing Stack 📉
// A monotonic decreasing stack maintains elements in decreasing order (from bottom to top).
// This means:

// The top of the stack always has the largest element.
// When pushing a new element, pop elements from the stack if they are smaller than or equal to the current element.

// NEXT GREATER ELEMENT 
// It uses monotonic decreasing stack.

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nge; // Store next greater elements
    stack<int> st; // Monotonic decreasing stack

    // Traverse nums2 from left to right
    for (int num : nums2) {
        while (!st.empty() && st.top() < num) {
            nge[st.top()] = num; // Map the next greater element
            st.pop();
        }
        st.push(num);
    }

    // Elements remaining in stack have no greater element
    while (!st.empty()) {
        nge[st.top()] = -1;
        st.pop();
    }

    // Get results for nums1
    vector<int> ans;
    for (int num : nums1) {
        ans.push_back(nge[num]);
    }
    return ans;
}

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> result = nextGreaterElement(nums1, nums2);

    for (int x : result) {
        cout << x << " ";
    }
    return 0;
}
