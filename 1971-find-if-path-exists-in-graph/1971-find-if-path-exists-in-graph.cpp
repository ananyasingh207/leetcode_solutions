class Solution {
public:
    vector<vector<int>> adj;
    
    void buildAdj(vector<vector<int>>& edges){
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n==0){
            return true;
        }
        unordered_map<int,bool> visited;
        adj.resize(n);
        buildAdj(edges);
        queue<int> eq;
        eq.push(source);
        visited[source] = true;
        while(!eq.empty()){
            int front = eq.front();
            eq.pop();
            if(front==destination){
                return true;
            }
            for(auto nb : adj[front]){
                if(!visited[nb]){
                    visited[nb] = true;
                    eq.push(nb);
                }
            }
        }
        return false;
    }
};