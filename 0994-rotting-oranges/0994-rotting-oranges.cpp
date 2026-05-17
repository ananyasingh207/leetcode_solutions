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
        vector<int> dr = {1,0,0,-1};
        vector<int> dc = {0,1,-1,0};
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            int i = temp.first.first;
            int j = temp.first.second;
            int t = temp.second;
            ans = max(ans, t);
            for(int k=0;k<4;k++){
                int r = i+dr[k];
                int c = j+dc[k];
                if(r>=0 && c>=0 && r<n && c<m && !visited[r][c] && grid[r][c]==1){
                    q.push({{r,c},t+1});
                    visited[r][c] = true;
                    fresh--;
                }
            }
        }
        if(fresh>0){
            return -1;
        }
        return ans;
    }
};