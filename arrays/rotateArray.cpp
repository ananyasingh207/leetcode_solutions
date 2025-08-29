#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int>& nums, int start, int end) {
    while (start < end) { 
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotateRight(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    if (k == 0) return;

    reverse(nums, 0, n-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, n-1);
}

void rotateLeft(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    if (k == 0) return;

    reverse(nums, 0, k-1);
    reverse(nums, k, n-1);
    reverse(nums, 0, n-1);
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7};

    cout << "Original: ";
    for (int x : nums) cout << x << " ";
    cout << "\n";

    rotateRight(nums, 3);
    cout << "After right rotate by 3: ";
    for (int x : nums) cout << x << " ";
    cout << "\n";

    rotateLeft(nums, 3);
    cout << "After left rotate by 3: ";
    for (int x : nums) cout << x << " ";
    cout << "\n";

    return 0;
}
