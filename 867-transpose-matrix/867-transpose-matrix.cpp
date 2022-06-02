class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> res;
        for(int i=0;i<m;i++)
        {
            vector<int> ans;
            for(int j=0;j<n;j++)
            {
                ans.push_back(mat[j][i]);
            }
            res.push_back(ans);
        }
        return res;
    }
};