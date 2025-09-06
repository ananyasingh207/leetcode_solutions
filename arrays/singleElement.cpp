#include <bits/stdc++.h>
using namespace std;

// ----------- Binary Search Solution (O(log n)) -----------
class SolutionBinarySearch {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int high = nums.size() - 1;
        int low = 0;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mid % 2 == 1) {
                mid--;  // make mid even
            }
            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2;
            } else {
                high = mid;
            }
        }
        return nums[low];
    }
};

// ----------- XOR Solution (O(n)) -----------
class SolutionXOR {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res = res ^ nums[i];
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,1,2,3,3,4,4,8,8};

    cout << "Input array: ";
    for (int num : nums) cout << num << " ";
    cout << "\n";

    SolutionBinarySearch sol1;
    int result1 = sol1.singleNonDuplicate(nums);
    cout << "Binary Search result: " << result1 << endl;

    SolutionXOR sol2;
    int result2 = sol2.singleNonDuplicate(nums);
    cout << "XOR result: " << result2 << endl;

    return 0;
}
