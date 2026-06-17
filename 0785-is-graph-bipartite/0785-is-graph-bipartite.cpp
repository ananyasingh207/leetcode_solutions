class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n==0 || n==1){
            return true;
        }
        queue<int> q;
        vector<int> color(n,-1);
        bool toggle = false;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                q.push(i);
                color[i] = 0;
                while(!q.empty()){
                int front = q.front();
                q.pop();
                for(auto node : graph[front]){
                    if(color[node]==-1){
                        q.push(node);
                        color[node] = !color[front];
                    }
                    else if(color[node]!=-1 && color[node]==color[front]){
                        return false;
                    }
                }
            }
            }
        }
        return true;
    }
};