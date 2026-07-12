class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int>& a, vector<int>& b){
            if(a[0]==b[0]) return a[1]<b[1];
            else return a[0]<b[0];
        });
        int lastInterval = intervals[0][1];
        int overlap = 0;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<lastInterval){
                overlap++;
                lastInterval = min(lastInterval,intervals[i][1]);
            }
            else{
                lastInterval = intervals[i][1];
            }
        }
        return overlap;
    }
};