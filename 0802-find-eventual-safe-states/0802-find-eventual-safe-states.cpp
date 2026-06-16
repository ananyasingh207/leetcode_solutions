class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outdegree(n,0);
        vector<vector<int>> rev(n);
        for(int i=0;i<n;i++){
            for(auto node : graph[i]){
                outdegree[i]++;
                rev[node].push_back(i);
            }
        }
        queue<int> q;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(outdegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto parent : rev[front]){
                outdegree[parent]--;
                if(outdegree[parent]==0){
                    q.push(parent);
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(outdegree[i]<=0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};