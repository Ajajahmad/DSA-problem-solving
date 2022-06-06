class Solution {
public:
    vector<int> getRow(int r) {
        int n = r+1;
        vector<vector<int>> res;
        for(int i=0;i<n;i++)
        {
            vector<int> ans;
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i) ans.push_back(1);
                else
                {
                    int value = res[i-1][j-1] + res[i-1][j];
                    ans.push_back(value);
                }
            }
            res.push_back(ans);
        }
        return res[n-1];
    }
};