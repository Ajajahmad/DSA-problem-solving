class Solution {
public:
    int dp[110][110];
    
    int uniquePaths(int m, int n) {
        memset(dp , -1, sizeof(dp));
        return solve(0,0,m,n);
    }
    int solve(int i, int j, int m, int n)
    {
        if(i<0 || j<0 || i>=m || j>=n) return 0;
        
        if(i==m-1 && j==n-1)
        {
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        
        int a = solve(i+1, j , m , n);
        int b = solve(i,j+1, m , n);
        return dp[i][j]  = a+b;
    }
};