#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Linear scan: O(n)
    int peakIndexLinear(vector<int>& arr) {
        for (int i = 1; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                return i;
            }
        }
        return -1; 
    }

    // Binary search: O(log n)
    int peakIndexBinary(vector<int>& arr) {
        int low = 1, high = arr.size() - 2; // peak can't be at ends
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid;
            }

            // If slope is increasing, move right
            if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1]) {
                low = mid + 1;
            }
            // Otherwise move left
            else {
                high = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {0, 2, 4, 6, 5, 3, 1};

    cout << "Peak Index (Linear): " << sol.peakIndexLinear(arr) << endl;
    cout << "Peak Index (Binary): " << sol.peakIndexBinary(arr) << endl;

    return 0;
}
