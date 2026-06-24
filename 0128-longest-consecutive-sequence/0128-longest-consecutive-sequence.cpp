class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || n==1){
            return n;
        }
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int maxCount = 0;
        for(auto num : st){
            int count = 1;
            if(!st.count(num-1)){
                int curr = num;
                while(st.count(curr+1)){
                    count++;
                    curr++;
                }
                maxCount = max(count,maxCount);
            }
        }
        return maxCount;
    }
};