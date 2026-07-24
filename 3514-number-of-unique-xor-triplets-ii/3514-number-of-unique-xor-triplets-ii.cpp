class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        vector<int> pairXor(2048, 0);
        vector<int> tripleXor(2048, 0);

        // Compute all possible pair XORs
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pairXor[nums[i] ^ nums[j]] = 1;
            }
        }

        // Generate triplet XORs
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2048; j++) {
                if (pairXor[j]) {
                    tripleXor[j ^ nums[i]] = 1;
                }
            }
        }

        // Count distinct XOR values
        int cnt = 0;
        for (int x : tripleXor) {
            if (x) cnt++;
        }

        return cnt;
    }
};