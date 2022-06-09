class Solution {
public:
    int dp[201][201];
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(grid,n-1,m-1);
        
    }
    int solve(vector<vector<int>> &grid , int i,int j)
    {
        if(i==0 &&j==0)
        {
            return grid[0][0];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(i>0 && j>0)
            return dp[i][j] = grid[i][j] + min(solve(grid,i-1,j) , solve(grid, i ,j-1));
        else if(i==0)
            return dp[i][j] = grid[i][j] + solve(grid,i,j-1);
        else if(j==0)
            return dp[i][j]= grid[i][j] + solve(grid , i-1,j);
        
        return 0;
                
    }
};