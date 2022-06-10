class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> res;
        if(n==0) return res;
        vector<string> str=strs;
        for(int i=0;i<n;i++)
        {
            sort(str[i].begin(),str[i].end());
        }
        unordered_map<string,vector<int>> mp;
        for(int i=0;i<n;i++)
        {
            mp[str[i]].push_back(i);
        }
        for(auto it:mp)
        {
            vector<string>ans;
            for(int i=0;i<it.second.size();i++)
            {
                int index = it.second[i];
                ans.push_back(strs[index]);
            }
            res.push_back(ans);
        }
        return res;
    }
};