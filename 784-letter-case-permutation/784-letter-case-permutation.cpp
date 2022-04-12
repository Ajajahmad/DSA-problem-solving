class Solution {
public:
    void solve(string s , vector<string> &res , string &ds , int i)
    {
        if(i==s.length())
        {
            res.push_back(ds);
            return;
        }
        if(!isalpha(s[i]))
        {
            ds.push_back(s[i]);
            solve(s, res , ds ,i+1);
            ds.pop_back();
        }
        else
        {
            ds.push_back(s[i]);
            solve(s,res,ds,i+1);
            ds.pop_back();
            if(islower(s[i]))
            {
                s[i]=toupper(s[i]);
                ds.push_back(s[i]);
                solve(s,res, ds, i+1);
                ds.pop_back();
                s[i]=tolower(s[i]);
            }
            else
            {
                s[i]=tolower(s[i]);
                ds.push_back(s[i]);
                solve(s,res, ds, i+1);
                ds.pop_back();
                s[i]=toupper(s[i]);
            }
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        string ds="";
        solve(s, res, ds , 0);
        return res;
    }
};