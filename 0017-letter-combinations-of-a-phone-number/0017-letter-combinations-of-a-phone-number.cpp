class Solution {
public:
    void helper(string& digits, vector<string>& ans, string res, int index, unordered_map<char, string>& phone) {
        if (index == digits.size()) {
            ans.push_back(res);
            return;
        }
        for (auto x : phone[digits[index]]) {
            res.push_back(x);
            helper(digits,ans,res,index+1,phone);
            res.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
        unordered_map<char, string> phone;
        phone['2'] = "abc";
        phone['3'] = "def";
        phone['4'] = "ghi";
        phone['5'] = "jkl";
        phone['6'] = "mno";
        phone['7'] = "pqrs";
        phone['8'] = "tuv";
        phone['9'] = "wxyz";
        vector<string> ans;
        helper(digits, ans, "", 0, phone);
        return ans;
    }
};