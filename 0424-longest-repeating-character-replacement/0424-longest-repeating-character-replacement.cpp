class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> freq(26,0);
        int maxLen = 0;
        int maxFreq = 0;
        int j = 0;
        for(int i=0;i<n;i++){
            freq[s[i]-'A']++;
            maxFreq = max(maxFreq,freq[s[i]-'A']);
            int windowSize = i-j+1;
            int canReplace = windowSize - maxFreq;
            while(canReplace>k){
                freq[s[j]-'A']--;
                j++;
                int windowMax = 0;
                for(int k=0;k<26;k++){
                    windowMax = max(windowMax,freq[k]);
                }
                canReplace = i-j+1 - windowMax;
            }
            maxLen = max(maxLen,i-j+1);
        }
        return maxLen;
    }
};