class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int node){
        visited[node]=true;
        for(int i : adj[node]){
            if(!visited[i]){
                dfs(adj,visited,i);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<vector<int>> adj(n);
        for(auto edge : connections){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int components = 0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,visited,i);
                components++;
            }
        }
        return components-1;
    }
};