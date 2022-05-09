class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<int,string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        vector<string> res;
        int n = digits.length();
        if(n==0) return res;
        string ans="";
        solve(digits,ans, res, mp, 0 , n);
        return res;
    }
    void solve(string digits,string ans,vector<string> &res , map<int,string> &mp, int i, int n )
    {
        if(i==n)
        {
            res.push_back(ans);
            return ; 
        }
        int value = digits[i]-'0';
        string str = mp[value];
        for(int j = 0;j<str.length();j++)
        {
            ans.push_back(str[j]);
            solve(digits,ans, res,mp,i+1, n);
            ans.pop_back();
        }
    }
};