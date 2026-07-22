class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int sign = 1;
        long long num = 0;
        int i = 0;
        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i<n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i<n && s[i] == '+') {
            i++;
        }
        while (i < n && isdigit(s[i]) ) {
            int digit = s[i]-'0';
            if(sign==1 && (num>INT_MAX/10 || (num==INT_MAX/10 && digit > 7))){
                return INT_MAX;
            }
            else if(sign==-1 && (num>INT_MAX/10 || (num==INT_MAX/10 && digit > 8))){
                return INT_MIN;
            }
            num = num*10 + digit;
            i++;
        }
        return num * sign;
    }
};