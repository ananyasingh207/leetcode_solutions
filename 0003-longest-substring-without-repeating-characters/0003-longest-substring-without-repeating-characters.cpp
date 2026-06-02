class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        int mlen = 0;
        unordered_map<int, int> visited;
        while(i<n && j<n){
            if(!visited[s[j]]){
                visited[s[j]]=1;
                mlen = max(mlen,j-i+1);
                j++;
            }
            else{
                visited[s[i]]=0;
                i++;
            }
        }
        return mlen;
    }
};