class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>> q;
        int fresh = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=true;
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int ans = 0;
        vector<int> dx = {0,1,-1,0};
        vector<int> dy = {1,0,0,-1};
        while(!q.empty()){
            auto front = q.front();
            int r = front.first.first;
            int c = front.first.second;
            int steps = front.second;
            ans = max(ans,steps);
            q.pop();
            for(int i=0;i<4;i++){
                int row = r+dx[i];
                int col = c+dy[i];
                if(row>=0 && row<n && col>=0 && col<m && !visited[row][col] && grid[row][col]==1){
                    q.push({{row,col},steps+1});
                    visited[row][col]=true;
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