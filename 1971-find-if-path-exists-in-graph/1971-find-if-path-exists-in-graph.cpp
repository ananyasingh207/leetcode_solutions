class Solution {
public:
    vector<vector<int>> adj;
    unordered_map<int,bool> visited;

    void buildAdj(vector<vector<int>>& edges){
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    bool dfs(vector<vector<int>>& adj, int source, int destination){
        if(source==destination){
            return true;
        }
        visited[source] = true;
        for(auto node : adj[source]){
            if(!visited[node]){
                if(dfs(adj,node,destination)){
                    return true;
                }
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n==0){
            return true;
        }
        adj.resize(n);
        buildAdj(edges);
        return dfs(adj,source,destination);
    }
};