#include <bits/stdc++.h>
using namespace std;

//
// 1. XOR Approach (Best O(n), O(1))
//
int missingNumber_XOR(vector<int>& nums) {
    int n = nums.size();
    int result = n; // include n in XOR
    for (int i = 0; i < n; i++) {
        result ^= i ^ nums[i];
    }
    return result;
}

//
// 2. Sum Formula Approach (O(n), O(1))
//
int missingNumber_Sum(vector<int>& nums) {
    int n = nums.size();
    int expected = n * (n + 1) / 2;
    int actual = accumulate(nums.begin(), nums.end(), 0);
    return expected - actual;
}

//
// 3. Sorting + Linear Scan (O(n log n), O(1))
//
int missingNumber_Sort(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == ans) {
            ans++;
        } else {
            break;
        }
    }
    return ans;
}

//
// 4. Hashing / Set Approach (O(n), O(n))
//
int missingNumber_Hash(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end());
    for (int i = 0; i <= nums.size(); i++) {
        if (!st.count(i)) return i;
    }
    return -1; // should never reach
}

//
// 5. Binary Search on Sorted Array (O(n log n), O(1))
//
int missingNumber_BinarySearch(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int l = 0, r = nums.size();
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] > mid) r = mid;
        else l = mid + 1;
    }
    return l;
}

//
// Sample Main Function
//
int main() {
    vector<int> nums = {3, 0, 1}; // Missing number = 2
    
    cout << "Input: [3,0,1]" << endl;
    cout << "XOR Method: " << missingNumber_XOR(nums) << endl;

    nums = {3,0,1}; // reset
    cout << "Sum Formula: " << missingNumber_Sum(nums) << endl;

    nums = {3,0,1}; // reset
    cout << "Sorting + Linear Scan: " << missingNumber_Sort(nums) << endl;

    nums = {3,0,1}; // reset
    cout << "Hashing/Set: " << missingNumber_Hash(nums) << endl;

    nums = {3,0,1}; // reset
    cout << "Binary Search: " << missingNumber_BinarySearch(nums) << endl;

    return 0;
}
