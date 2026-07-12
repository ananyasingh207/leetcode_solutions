class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int>& a, vector<int>& b){
            if(a[0]==b[0]) return a[1]<b[1];
            else return a[0]<b[0];
        });
        vector<vector<int>> lastInterval;
        lastInterval.push_back(intervals[0]);
        int overlap = 0;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<lastInterval.back()[1] && intervals[i][1]>lastInterval.back()[0]){
                overlap++;
                lastInterval.back()[1] = min(lastInterval.back()[1],intervals[i][1]);
            }
            else{
                lastInterval.back()[1] = intervals[i][1];
            }
        }
        return overlap;
    }
};