class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto edge : flights){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v,w});
        }
        queue<pair<pair<int,int>,int>> q;
        vector<int> dist(n,INT_MAX);
        q.push({{src,0},0});
        while(!q.empty()){
            auto front = q.front();
            int node = front.first.first;
            int wt = front.first.second;
            int stops = front.second;
            q.pop();
            if(stops>k) continue;
            for(auto nb : adj[node]){
                int nbNode = nb.first;
                int nbWt = nb.second;
                if(dist[nbNode]>nbWt+wt){
                    dist[nbNode]=nbWt+wt;
                    q.push({{nbNode,nbWt+wt},stops+1});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};