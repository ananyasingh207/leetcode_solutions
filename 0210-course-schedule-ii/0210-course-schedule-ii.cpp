class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto edge : prerequisites){
            int u = edge[0];
            int v = edge[1];
            adj[v].push_back(u);
        }
        vector<int> indegree(numCourses);
        for(int i=0;i<numCourses;i++){
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
            for(auto nb : adj[front]){
                indegree[nb]--;
                if(indegree[nb]==0){
                    q.push(nb);
                }
            }
        }
        if(ans.size()!=numCourses){
            return {};
        }
        return ans;
    }
};