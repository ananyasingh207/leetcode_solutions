class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int col, int node, int n){
        color[node] = col;
        for(auto nb : graph[node]){
            if(color[nb]==-1){
                if(!dfs(graph,color,!col,nb,n)) return false;
            }
            else if(color[nb]==col) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n==0 || n==1){
            return true;
        }
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
               if(!dfs(graph,color,0,i,n)) return false;
            }
        }
        return true;
    }
};