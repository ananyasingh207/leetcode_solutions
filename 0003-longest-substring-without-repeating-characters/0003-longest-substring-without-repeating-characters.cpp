class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        unordered_map<char,int> visited;
        int maxLen = 0;
        for(int i=0;i<n;i++){
            while(visited[s[i]]){
                visited[s[j]]=false;
                j++;
            }
            visited[s[i]]=true;
            maxLen = max(maxLen,i-j+1);
        }
        return maxLen;
    }
};