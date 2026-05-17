class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int fresh = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int ans = 0;
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            int i = temp.first.first;
            int j = temp.first.second;
            int t = temp.second;
            ans = max(ans, t);
            if (i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] == 1) {
                q.push({{i - 1, j}, t + 1});
                visited[i - 1][j] = true;
                fresh--;
            }
            if (j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] == 1) {
                q.push({{i, j - 1}, t + 1});
                visited[i][j - 1] = true;
                fresh--;
            }
            if (j + 1 < m && !visited[i][j + 1] && grid[i][j + 1] == 1) {
                q.push({{i, j + 1}, t + 1});
                visited[i][j + 1] = true;
                fresh--;
            }
            if (i + 1 < n && !visited[i + 1][j] && grid[i + 1][j] == 1) {
                q.push({{i + 1, j}, t + 1});
                visited[i + 1][j] = true;
                fresh--;
            }
        }
        if(fresh>0){
            return -1;
        }
        return ans;
    }
};