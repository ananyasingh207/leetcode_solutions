class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans;
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            if(ch=='('){
                if(!st.empty()){
                    ans+=ch;
                }
                st.push(ch);
            }
            else if(ch==')'){
                st.pop();
                if(!st.empty()){
                    ans+=ch;
                }
            }
        }
        return ans;
    }
};