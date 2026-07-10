class Solution {
public:
    vector<vector<int>> dp;
    bool helper(string& s, int n, vector<vector<int>>& dp, int index, int count){
        if(count<0) return false;
        if(index==n){
            return (count==0);
        }
        if(dp[index][count]!=-1) return dp[index][count];
        if(s[index]=='(') 
            return helper(s,n,dp,index+1,count+1);
        else if(s[index]==')') 
            return helper(s,n,dp,index+1,count-1);
        else{
            dp[index][count] = helper(s,n,dp,index+1,count+1) || helper(s,n,dp,index+1,count-1) 
            || helper(s,n,dp,index+1,count);
            return dp[index][count];
        }
        
    }
    
    bool checkValidString(string s) {
        int n = s.length();
        dp.resize(n, vector<int>(n,-1));
        return helper(s,n,dp,0,0);
    }
};