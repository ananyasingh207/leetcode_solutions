class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        unordered_map<char, int> mp = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };
        int num = 0;
        int prev = 0;
        for(int i=n-1;i>=0;i--){
            if(mp[s[i]]<prev){
                num-=mp[s[i]];
            }
            else{
                num+=mp[s[i]];
            }
            prev = mp[s[i]];
        }
        return num;
    }
};