class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        unordered_map<char, int> mpt;
        unordered_map<char, int> mps;
        for(int i=0;i<m;i++){
            mpt[t[i]]++;
        }
        pair<int,int> minString = {INT_MAX,-1};
        int j  = 0;
        for(int i=0;i<n;i++){
            mps[s[i]]++;
            while (true) {
                bool valid = true;
                for (auto it : mpt) {
                    if (mps[it.first] < it.second) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) break;
                if(i-j+1 < minString.first){
                    minString.first =  i - j + 1;
                    minString.second = j;
                }
                mps[s[j]]--;
                j++;
            }
        }
        if (minString.first == INT_MAX)
            return "";

        return s.substr(minString.second, minString.first);
    }
};