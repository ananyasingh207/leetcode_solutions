class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        next_permutation(str.begin(),str.end());
        string maxIntStr = to_string(numeric_limits<int>::max());
        if (str.length() == maxIntStr.length() && str > maxIntStr) {
            return -1; 
        }
        int ans = stoi(str);
        if(ans>n){
            return ans;
        }
        else{
            return -1;
        }
    }
};