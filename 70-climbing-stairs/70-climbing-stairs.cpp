class Solution {
public:
    
    int climbStairs(int n) {
        int dp[n+1];
        memset(dp , -1, sizeof(dp));
        
        return solve(n,dp);
    }
    int solve(int n, int dp[])
    {
        if(n<=2) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n]  = solve(n-1, dp) + solve(n-2, dp);
    }
};