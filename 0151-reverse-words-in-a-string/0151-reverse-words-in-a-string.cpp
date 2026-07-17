class Solution {
public:
    string reverse(string& str){
        int i = 0;
        int j = str.length()-1;
        while(i<j){
            int temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            i++;j--;
        }
        return str;
    }

    string reverseWords(string s) {
        int n = s.length();
        vector<string> words;
        int i = 0;
        int j = 0;
        while(i<n && j<n){
            //trailing spaces
            while(i<n && s[i]==' '){
                i++;
            }
            if(i>=n) break;
            j = i;
            //end of the word
            while(j<n && s[j]!=' '){
                j++;
            }
            words.push_back(s.substr(i,j-i));
            i = j;
        }
        string ans = "";
        for(int i=words.size()-1;i>=0;i--){
            ans+=words[i];
            if(i!=0) ans+=' ';
        }
        return ans;
    }
};