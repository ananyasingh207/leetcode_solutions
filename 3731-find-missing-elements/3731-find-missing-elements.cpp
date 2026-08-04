class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int mn = INT_MAX;
        int mx = INT_MIN;
        vector<int> ans;
        unordered_map<int,bool> mp;
        for(int i=0;i<n;i++){
            mn = min(mn,nums[i]);
            mx = max(mx,nums[i]);
            mp[nums[i]]=true;
        }
        for(int i=mn;i<=mx;i++){
            if(mp.count(i)) continue;
            else ans.push_back(i);
        }
        return ans;
    }
};