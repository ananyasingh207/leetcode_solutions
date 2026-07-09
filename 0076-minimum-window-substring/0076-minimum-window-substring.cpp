class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        unordered_map<char, int> mp;
        for(int i=0;i<m;i++){
            mp[t[i]]++;
        }
        int l = 0;
        int r = 0;
        int count = 0;
        pair<int, int> minString = {INT_MAX,-1};
        while(r<n){
            if(mp[s[r]]>0) count++;
            mp[s[r]]--;
            while(count==m){
                if(r-l+1 < minString.first){
                    minString.first = r-l+1;
                    minString.second = l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) count--;
                l++; 
            }
            r++;
        }
        return minString.first == INT_MAX ? "" : s.substr(minString.second,minString.first);
    }
};