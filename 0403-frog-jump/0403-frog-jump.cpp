class Solution {
public:
    unordered_map<int, int> mp;
    bool frogJump(vector<int>& stones, int n, int index, int k, vector<vector<int>>& dp){
        if(index>n-1){
            return false;
        }
        if(index==n-1){
            return true;
        }
        if(index==0 && index+1<n-1){
            if(abs(stones[index]-stones[index+1])!=1){
                return false;
            }
        }
        if(dp[index][k]!=-1){
            return dp[index][k];
        }
        if(k==0){
            auto it = mp.find(stones[index]+k+1);
            if(it==mp.end()) return false;
            int idx = it->second;
            return frogJump(stones,n,idx,k+1,dp);
        }
        bool move = false;
        auto it = mp.find(stones[index]+k);
        if(it!=mp.end()){
            int idx = it->second;
            move = frogJump(stones,n,idx,k,dp);
        }
        bool moveplus = false;
        it = mp.find(stones[index]+k+1);
        if(it!=mp.end()){
            int idx = it->second;
            moveplus = frogJump(stones,n,idx,k+1,dp);
        }
        bool moveminus = false;
        if(k>1){
            it = mp.find(stones[index]+k-1);
            if(it!=mp.end()){
                int idx = it->second;
                moveminus = frogJump(stones,n,idx,k-1,dp);
            }
        }
        dp[index][k] = move || moveplus || moveminus;
        return dp[index][k];
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return frogJump(stones,n,0,0,dp);
    }
};