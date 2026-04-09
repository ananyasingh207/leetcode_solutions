class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, bool> visited;
        int n = s.length();
        int i = 0;
        int j = 0;
        int mlen = 0;
        while(i<n && j<n){
            if(!visited[s[j]]){
                visited[s[j]] = true;
                mlen = max(mlen,j-i+1);
                j++;
            }
            else if(visited[s[j]]){
                visited[s[i]]=false;
                i++;
            }
        }
        return mlen;
    }
};