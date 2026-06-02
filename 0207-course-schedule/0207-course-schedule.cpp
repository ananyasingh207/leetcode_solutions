class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto edge: prerequisites){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        int n = adj.size();
        vector<int> indegree(numCourses,0);
        for(int i=0;i<n;i++){
            for(auto node : adj[i]){
                indegree[node]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int front = q.front();
            ans.push_back(front);
            q.pop();
            for(auto node : adj[front]){
                indegree[node]--;
                if(indegree[node]==0){
                    q.push(node);
                }
            }
        }
        if(ans.size()==numCourses){
            return true;
        }
        return false;
    }
};