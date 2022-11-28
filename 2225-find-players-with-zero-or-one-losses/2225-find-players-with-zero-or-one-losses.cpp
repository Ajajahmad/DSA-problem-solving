class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
        vector<vector<int>> res(2);
        unordered_map<int ,int> w,l;
        for(int i=0;i<m.size();i++)
        {
            w[m[i][0]]++;
            l[m[i][1]]++;
        }
        
        for(auto it:w)
        {
            if(l.find(it.first)==l.end()) res[0].push_back(it.first);
        }
        for(auto it:l)
        {
            if(it.second==1) res[1].push_back(it.first);
        }
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        return res;
    }
};