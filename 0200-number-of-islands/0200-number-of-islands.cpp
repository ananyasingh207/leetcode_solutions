class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col, int n, int m){
        queue<pair<int, int>> q;
        q.push({row,col});
        int dx[] = {1,0,0,-1};
        int dy[] = {0,1,-1,0};
        while(!q.empty()){
            auto front = q.front();
            int r = front.first;
            int c = front.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nb_r = r + dx[i];
                int nb_c = c + dy[i];
                if(nb_r>=0 && nb_c>=0 && nb_r<n && nb_c<m && grid[nb_r][nb_c]=='1' && !visited[nb_r][nb_c]){
                    q.push({nb_r,nb_c});
                    visited[nb_r][nb_c] = true;
                }
            }
        }
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c, int n, int m){
        if(r>=n || r<0 || c>=m || c<0 ){
            return;
        }
        if(visited[r][c] || grid[r][c]!='1'){
            return;
        }
        visited[r][c] = true;
        dfs(grid, visited, r+1 , c ,n,m);
        dfs(grid, visited, r , c+1 ,n,m);
        dfs(grid, visited, r-1 , c ,n,m);
        dfs(grid, visited, r , c-1 ,n,m);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int island = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    island++;
                    dfs(grid, visited, i, j, n, m);
                }
            }
        }
        return island;
    }
};