class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int originalColor = image[sr][sc];
        image[sr][sc] = color;
        vector<int> dr = {1,0,0,-1};
        vector<int> dc = {0,1,-1,0};
        while(!q.empty()){
            auto front = q.front();
            int row = front.first;
            int col = front.second;
            q.pop();
            for(int i=0;i<4;i++){
                int r = row+dr[i];
                int c = col+dc[i];
                if(r>=0 && r<n && c>=0 && c<m && image[r][c]!=color && image[r][c]==originalColor){
                    q.push({r,c});
                    image[r][c]=color;
                }
            }
        }
        return image;
    }
};