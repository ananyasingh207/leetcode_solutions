class Solution {
public:
    const int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto edge : roads){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            long long wt = top.first;
            int node = top.second;
            if(wt>dist[node]) continue;
            for(auto nb : adj[node]){
                int nb_wt = nb.second;
                int nb_node = nb.first;
                long long newDist = dist[node]+nb_wt;
                if(dist[nb_node]>newDist){
                    dist[nb_node]=newDist;
                    ways[nb_node]=ways[node];
                    pq.push({newDist,nb_node});
                }
                else if(newDist==dist[nb_node]){
                    ways[nb_node]=(ways[node]+ways[nb_node])%MOD;
                }
            }
        }
        return ways[n-1];
    }
};