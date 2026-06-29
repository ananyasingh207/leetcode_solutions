class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        int count = 0;
        int j = 0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while(mp['a']>0 && mp['b']>0 && mp['c']>0 && j<n){
                mp[s[j]]--;
                j++;
            }
            count+=j;
        }
        return count;
    }
};