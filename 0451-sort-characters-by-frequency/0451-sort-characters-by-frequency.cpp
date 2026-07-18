class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(int i=0;i<s.length();i++){
            freq[s[i]]++;    
        }
        vector<pair<char, int>> v(freq.begin(),freq.end());
        sort(v.begin(),v.end(),[](const auto &a, const auto& b){
            return a.second>b.second;
        });
        string res = "";
        for(auto i : v){
            char key = i.first;
            int f = i.second;
            while(f>0){
                res+=key;
                f--;
            }
        }
        return res;
    }
};