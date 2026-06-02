class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq_mp;
        for(int i=0;i<n;i++){
            freq_mp[nums[i]]++;
        }
        vector<pair<int,int>> freq(freq_mp.begin(),freq_mp.end());
        sort(freq.begin(),freq.end(), [](const auto& a, const auto& b){
            if(a.second==b.second){
                return a.first > b.first;
            }
            return a.second > b.second;
        });
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(freq[i].first);
        }
        return ans;
    }
};