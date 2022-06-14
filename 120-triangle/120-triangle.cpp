class Solution {
public:
    int dp[201][201];
    int minimumTotal(vector<vector<int>>& tri) {
        memset(dp,-1,sizeof(dp));
        return solve(tri,0,0);
    }
    int solve(vector<vector<int>>& tri , int i , int j)
    {
        int n = tri.size();
        if(i==n)
        {
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = tri[i][j]+min(solve(tri,i+1,j) , solve(tri , i+1, j+1));
    }
};