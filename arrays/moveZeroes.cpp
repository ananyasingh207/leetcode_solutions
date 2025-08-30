#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ----------------------------
    // Approach 1: Brute Force
    // ----------------------------
    // Idea: Collect non-zero elements into a new array,
    // then fill the rest with zeros.
    // Time: O(n), Space: O(n)
    void moveZeroesBrute(vector<int>& nums) {
        vector<int> temp;

        // Step 1: Store all non-zero elements
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                temp.push_back(nums[i]);
            }
        }

       for(int i=temp.size();i<nums.size();i++){
            temp.push_back(0);
       }

       nums = temp;
    }

    // ----------------------------
    // Approach 2: Shift + Overwrite
    // ----------------------------
    // Idea: Use two pointers.
    // One pointer iterates, the other fills non-zero values.
    // Then fill remaining with zeros.
    // Time: O(n), Space: O(1)
    void moveZeroesShift(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;

        while (i < n) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
            i++;
        }

        while (j < n) {
            nums[j] = 0;
            j++;
        }
    }

    // ----------------------------
    // Approach 3: In-place Swap
    // ----------------------------
    // Idea: Whenever we see a non-zero, swap it into the
    // correct position using two pointers.
    // Time: O(n), Space: O(1)
    void moveZeroesSwap(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                if (i != j) {
                    swap(nums[i], nums[j]);
                }
                j++;
            }
        }
    }
};

int main() {
    Solution s;

    vector<int> arr1 = {0,1,0,3,12};
    vector<int> arr2 = {0,1,0,3,12};
    vector<int> arr3 = {0,1,0,3,12};

    cout << "Original: ";
    for (int x : arr1) cout << x << " ";
    cout << "\n";

    s.moveZeroesBrute(arr1);
    cout << "After Brute Force: ";
    for (int x : arr1) cout << x << " ";
    cout << "\n";

    s.moveZeroesShift(arr2);
    cout << "After Shift Approach: ";
    for (int x : arr2) cout << x << " ";
    cout << "\n";

    s.moveZeroesSwap(arr3);
    cout << "After Swap Approach: ";
    for (int x : arr3) cout << x << " ";
    cout << "\n";

    return 0;
}
