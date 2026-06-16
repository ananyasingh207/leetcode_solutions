class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    q.push({{i,j},0});
                    isWater[i][j]=0;
                }
                else if(isWater[i][j]==0){
                    isWater[i][j]=-1;
                }
            }
        }
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        while(!q.empty()){
            auto front = q.front();
            int row = front.first.first;
            int col = front.first.second;
            int dist = front.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nb_r = row+dx[i];
                int nb_c = col+dy[i];
                if(nb_r<n && nb_r>=0 && nb_c<m && nb_c>=0 && isWater[nb_r][nb_c]==-1){
                    q.push({{nb_r,nb_c},dist+1});
                    isWater[nb_r][nb_c] = dist+1;
                }
            }
        }
        return isWater;
    }
};