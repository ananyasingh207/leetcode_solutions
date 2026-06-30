class Solution {
public:
    int calPoints(vector<string>& s) {
        int score = 0;
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=="C"){
                if(!st.empty()){
                    st.pop();
                }
            }
            else if(s[i]=="+"){
                int prev1=0, prev2=0;
                if(!st.empty()){
                    prev1 = st.top();
                    st.pop();

                }
                if(!st.empty()){
                    prev2 = st.top();
                    st.pop();
                }
                st.push(prev2);
                st.push(prev1);
                st.push(prev1+prev2);
            }
            else if(s[i]=="D"){
                int prev = 0;
                if(!st.empty()){
                    prev = st.top();
                }
                st.push(prev*2);
            }
            else{

                st.push(stoi(s[i]));
            }
        }
        while(!st.empty()){
            score+=st.top();
            st.pop();
        }
        return score;
    }
};