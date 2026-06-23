class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        if(n<k){
            return s;
        }
        vector<pair<char, int>> st;
        st.push_back({s[0],1});
        for(int i=1;i<n;i++){
            if(!st.empty() && s[i]==st.back().first){
                st.back().second++;
            }
            else{
                st.push_back({s[i],1});
            }
            if(st.back().second==k){
                st.pop_back();
            }
        }
        string res;
        for(auto ch : st){
            while(ch.second){
                res+=ch.first;
                ch.second--;
            }
        }
        return res;
    }
};