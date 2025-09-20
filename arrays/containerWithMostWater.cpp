#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Brute Force Approach: O(n^2)
    int maxAreaBruteForce(vector<int>& height) {
        int n = height.size();
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int width = j - i;
                int length = min(height[i], height[j]);
                int area = width * length;
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }

    // Two Pointer Approach: O(n)
    int maxAreaTwoPointer(vector<int>& height) {
        int n = height.size();
        int maxArea = 0;
        int left = 0, right = n - 1;

        while (left < right) {
            int width = right - left;
            int h = min(height[left], height[right]);
            int area = width * h;
            maxArea = max(maxArea, area);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};

int main() {
    Solution sol;

    vector<int> height = {1,8,6,2,5,4,8,3,7};

    cout << "Max Area (Brute Force): " << sol.maxAreaBruteForce(height) << endl;

    cout << "Max Area (Two Pointer): " << sol.maxAreaTwoPointer(height) << endl;

    return 0;
}
