class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        map<int, pair<char,int>> mp;
        string res =strs[0];
        for(int i=0;i<res.length() ;i++) mp[i] = {res[i],1};
        for(int i=1;i<strs.size() ;i++)
        {
            res = strs[i];
            for(int j=0;j<res.length();j++)
            {
                char ch = res[j];
                if(mp[j].first==ch)
                {
                    mp[j].second++;
                    
                }
                else
                {
                    break;
                }
            }
        }
        
        
        res = "";
        int n = strs.size();
        for(auto it:mp)
        {
            if(it.second.second==n)
            {
                res+= it.second.first;
            }
        }
        return res;
    }
};