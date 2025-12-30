#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------
OPTIMIZED SOLUTION (Binary Search) – O(log n)
-------------------------------------------------
*/
class SolutionBinarySearch {
public:
    // Find first occurrence of target
    int firstIndex(vector<int>& nums, int target) {
        int ans = -1;
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ans = mid;          // store answer
                high = mid - 1;     // move left
            }
            else if (nums[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }

    // Find last occurrence of target
    int lastIndex(vector<int>& nums, int target) {
        int ans = -1;
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ans = mid;          // store answer
                low = mid + 1;      // move right
            }
            else if (nums[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return { firstIndex(nums, target), lastIndex(nums, target) };
    }
};

/*
-------------------------------------------------
BRUTE FORCE SOLUTION (Linear Scan) – O(n)
-------------------------------------------------
*/
class SolutionLinear {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int count = 0;

        // Count occurrences
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target)
                count++;
        }

        // Find first occurrence
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                ans[0] = i;
                break;
            }
        }

        // If only one occurrence
        if (count == 1) {
            ans[1] = ans[0];
            return ans;
        }

        // Find last occurrence
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == target) {
                ans[1] = i;
                break;
            }
        }

        return ans;
    }
};

/*
-------------------------------------------------
MAIN FUNCTION 
-------------------------------------------------
*/
int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    SolutionBinarySearch bs;
    SolutionLinear ls;

    vector<int> res1 = bs.searchRange(nums, target);
    vector<int> res2 = ls.searchRange(nums, target);

    cout << "Binary Search Result: ";
    cout << res1[0] << " " << res1[1] << endl;

    cout << "Linear Search Result: ";
    cout << res2[0] << " " << res2[1] << endl;

    return 0;
}
