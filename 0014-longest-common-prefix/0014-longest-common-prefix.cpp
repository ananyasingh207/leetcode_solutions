class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string first = strs[0];
        string res = "";
        for(int i=0;i<first.size();i++){
            char ch = first[i];
            for(int j=1;j<strs.size();j++){
                if(i>=strs[j].size() || ch!=strs[j][i]){
                    return first.substr(0,i);
                }
            }
        }
        return first;
    }
};