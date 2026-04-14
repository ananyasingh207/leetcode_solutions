class Solution {
public:
    using ll = long long;
    const ll INF = 1e15;

    ll solve(int i, int j, vector<int>& robots, vector<vector<int>>& factories, vector<vector<ll>>& dp) {
        int n = robots.size();
        int m = factories.size();

        if (i == n) return 0;

        if (j == m) return INF;

        if (dp[i][j] != -1) return dp[i][j];

        ll ans = INF;

        ans = solve(i, j + 1, robots, factories, dp);

        ll cost = 0;
        int factoryPos = factories[j][0];
        int capacity = factories[j][1];

        for (int k = 0; k < capacity && i + k < n; k++) {
            cost += abs(robots[i + k] - factoryPos);
            ans = min(ans, cost + solve(i + k + 1, j + 1, robots, factories, dp));
        }

        return dp[i][j] = ans;
    }

    long long minimumTotalDistance(vector<int>& robots, vector<vector<int>>& factories) {
        sort(robots.begin(), robots.end());
        sort(factories.begin(), factories.end());

        int n = robots.size();
        int m = factories.size();

        vector<vector<ll>> dp(n, vector<ll>(m, -1));

        return solve(0, 0, robots, factories, dp);
    }
};