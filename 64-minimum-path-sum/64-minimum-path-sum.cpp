class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int dp[n+1][m+1];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0&&j==0) dp[i][j] = grid[0][0];
                else if(i>0 && j>0) dp[i][j] = grid[i][j] + min(dp[i-1][j] , dp[i][j-1]);
                else if(i==0) dp[i][j] = grid[i][j] + dp[i][j-1];
                else if(j==0) dp[i][j] = grid[i][j] + dp[i-1][j];
            }
        }
        return dp[n-1][m-1];
            
        
        
    }
};