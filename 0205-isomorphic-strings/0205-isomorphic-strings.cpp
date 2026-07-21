class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n!=m) return false;
        vector<int> mapS(256,0);
        vector<int> mapT(256,0);
        for(int i=0;i<n;i++){
            char a = s[i];
            char b = t[i];
            if(mapS[a]==0 && mapT[b]==0){
                mapS[a] = b;
                mapT[b] = a;
            }
            else{
                if(mapS[a]!=b && mapT[b]!=a){
                    return false;
                }
            }
        }
        return true;
    }
};