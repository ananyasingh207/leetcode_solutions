class Solution {
public:
    void dfs(vector<bool>& visited, int n, vector<vector<int>>& isConnected, int node){
        if(visited[node]){
            return;
        }
        visited[node] = true;
        for(int i=0;i<n;i++){
            if(!visited[i] && isConnected[node][i]==1){
                dfs(visited,n,isConnected,i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n,false);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(visited,n,isConnected,i);
            }
        }
        return count;
    }
};