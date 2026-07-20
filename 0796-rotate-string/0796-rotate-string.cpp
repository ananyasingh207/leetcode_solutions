class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int g = goal.length();
        if(n!=g) return false;
        if(s==goal) return true;
        for(int i=0;i<n;i++){
            string rotated = s.substr(i) + s.substr(0,i);
            if(rotated==goal) return true;
        }
        return false;
    }
};