class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end(),[](vector<int>& a, vector<int>& b){
            return a[0]<b[0];
        });
        res.push_back(intervals[0]);
        int i = 0;
        while(i<n){
            if(intervals[i][0]<=res.back()[1] && intervals[i][1]>=res.back()[0]){
                res.back()[0] = min(intervals[i][0],res.back()[0]);
                res.back()[1] = max(intervals[i][1],res.back()[1]);
            }
            else{
                res.push_back(intervals[i]);
            }
            i++;
        }
        return res;
    }
};