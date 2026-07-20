class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";
        int maxLen = 0;
        int left = 0;
        int right = 0;
        for(int i=0;i<n;i++){
            left = i;
            right = i;
            while(left>=0 && right<n && s[left]==s[right]){
                if(right-left+1>maxLen){
                    maxLen = right-left+1;
                    ans = s.substr(left,maxLen);
                }
                right++;
                left--;
            }
            left = i;
            right = i+1;
            while(left>=0 && right<n && s[left]==s[right]){
                if(right-left+1>maxLen){
                    maxLen = right-left+1;
                    ans = s.substr(left,maxLen);
                }
                right++;
                left--;
            }
        }
        return ans;
    }
};