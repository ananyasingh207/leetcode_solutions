class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1) return -1;
        if(n==1) return 1;
        vector<int> dr = {1,0,0,-1,1,-1,1,-1};
        vector<int> dc = {0,1,-1,0,1,1,-1,-1};
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        visited[0][0]=true;
        while(!q.empty()){
            auto front = q.front();
            int row = front.first.first;
            int col = front.first.second;
            int steps = front.second;
            q.pop();
            for(int i=0;i<8;i++){
                int r = dr[i]+row;
                int c = dc[i]+col;
                if(r>=0 && r<n && c>=0 && c<n && !visited[r][c] && grid[r][c]==0){
                    if(r==n-1 && c==n-1){
                        return steps+1;
                    }
                    q.push({{r,c},steps+1});
                    visited[r][c]=true;
                }
            }
        }
        return -1;
    }
};