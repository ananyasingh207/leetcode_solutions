class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<long long> fact, invFact;

    void init(int n) {
        fact.resize(n + 1);
        invFact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++){
            fact[i] = fact[i - 1] * i % MOD;
        }

        invFact[n] = power(fact[n], MOD - 2);

        for (int i = n; i >= 1; i--){
            invFact[i - 1] = invFact[i] * i % MOD;
        }
    }

    long long power(long long a, long long b){
        long long ans = 1;
        while (b) {
            if (b & 1) ans = ans * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return ans;
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;

        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    
    int minMaxSums(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        init(n);

        long long ans = 0;

        for (int i=0;i<n; i++) {
            long long mx = 0;
            long long mn = 0;
            for (int j=0;j<=k-1;j++) {
                mx = (mx + nCr(i, j)) % MOD;
            }
            for (int j=0;j<=k-1;j++) {
                mn = (mn + nCr(n - 1 - i, j)) % MOD;
            }
            ans = (ans + nums[i] * ((mx + mn) % MOD)) % MOD;
        }

        return ans;
    }
};