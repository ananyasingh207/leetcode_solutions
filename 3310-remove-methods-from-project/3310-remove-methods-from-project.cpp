class Solution {
public:
    void dfsSus(vector<vector<int>>& adj, vector<bool>& visited, int node, set<int>& sus){
        if(visited[node]) return;
        sus.insert(node);
        visited[node]=true;
        for(int i : adj[node]){
            if(!visited[i]){
                dfsSus(adj,visited,i,sus);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto edge : invocations){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        vector<bool> visited(n,false);
        set<int> sus;
        dfsSus(adj,visited,k,sus);
        for(auto edge : invocations){
            int u = edge[0];
            int v = edge[1];
            if(sus.find(u)==sus.end() && sus.find(v)!=sus.end()){
                vector<int> ans;
                for(int i=0;i<n;i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(sus.find(i)!=sus.end()) continue;
            else ans.push_back(i);
        }
        return ans;
    }
};