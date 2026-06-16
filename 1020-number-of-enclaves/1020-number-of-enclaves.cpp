class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // if(n==0 || m==0){
        //     return 0;
        // }
        vector<vector<bool>> isSafe(n, vector<bool>(m,false));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==n-1 || j==m-1 || i==0 || j==0) && grid[i][j]==1){
                    q.push({i,j});
                    isSafe[i][j]=true;
                }
            }
        }
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        int landCells = 0;
        while(!q.empty()){
            auto front = q.front();
            int row = front.first;
            int col = front.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nb_r = row+dx[i];
                int nb_c = col+dy[i];
                if(nb_r<n-1 && nb_r>0 && nb_c<m-1 && nb_c>0 && !isSafe[nb_r][nb_c] && grid[nb_r][nb_c]==1){
                    q.push({nb_r,nb_c});
                    isSafe[nb_r][nb_c]=true;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!isSafe[i][j] && grid[i][j]==1){
                    landCells++;
                }
            }
        }
        return landCells;
    }
};