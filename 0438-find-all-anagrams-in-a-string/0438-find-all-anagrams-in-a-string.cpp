class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> freq(26,0);
        vector<int> window_freq(26,0);
        for(auto ch : p){
            freq[ch-'a']++;
        }
        vector<int> ids;
        int i = 0;
        int j = 0;
        while(j<n){
            window_freq[s[j]-'a']++;

            if(j-i+1 > m){
                window_freq[s[i]-'a']--;
                i++;
            }

            if(j-i+1 == m){
                if(window_freq==freq){
                    ids.push_back(i);
                }
            }
            j++;
        }
        return ids;
    }
};