#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                count++;
            } else if (nums[i] == 0) {
                count = 0;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 1, 0, 1, 1, 1};

    cout << "Input array: ";
    for (int num : nums) cout << num << " ";
    cout << "\n";

    int result = sol.findMaxConsecutiveOnes(nums);

    cout << "Max consecutive ones: " << result << endl;

    return 0;
}
