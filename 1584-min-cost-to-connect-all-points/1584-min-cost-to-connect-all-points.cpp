class Solution {
public:
    int manhattanDistance(int x1, int x2, int y1, int y2){
        return (abs(x1-x2) + abs(y1-y2));
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> mstSet(n,false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        int minCost = 0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int w = top.first;
            int node = top.second;
            if(mstSet[node]) continue;
            minCost+=w;
            mstSet[node]=true;
            for(int i=0;i<n;i++){
                if(!mstSet[i]){
                    // points[node][0], -> x1
                    // points[i][0],    -> x2
                    // points[node][1], -> y1
                    // points[i][1]     -> y2
                    int weight = manhattanDistance(points[node][0],points[i][0],points[node][1],points[i][1]);
                    pq.push({weight,i});
                }
            }
        }
        return minCost;
    }
};