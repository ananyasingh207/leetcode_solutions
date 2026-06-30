class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxLen = 0;
        int i = 0;
        int j = 0;
        vector<int> freq(26,0);
        int maxFreq = 0;
        while(i<n && j<n){
            freq[s[j]-'A']++;
            maxFreq = max(maxFreq,freq[s[j]-'A']);
            int windowSize = j-i+1;
            int toReplace = windowSize - maxFreq;
            while(toReplace>k){
                freq[s[i]-'A']--;
                int subFreq = 0;
                for(int k=0;k<26;k++){
                    subFreq = max(subFreq,freq[k]);
                }
                i++;
                windowSize = j-i+1;
                toReplace = windowSize - subFreq;
            }
            maxLen = max(windowSize,maxLen);
            j++;
        }
        return maxLen;
    }
};