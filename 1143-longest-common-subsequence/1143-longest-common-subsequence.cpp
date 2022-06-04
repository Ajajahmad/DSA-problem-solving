class Solution {
public:
    int dp[1001][1001];
    int longestCommonSubsequence(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        int n = s1.length();
        int m = s2.length();
        return solve(n,m,s1,s2);
    }
    int solve(int n, int m, string s1, string s2)
    {
        for(int i=0;i<n+1;i++) dp[i][0]=0;
        for(int i=0;i<m+1;i++) dp[0][i]=0;
        if(dp[n][m]!=-1) return dp[n][m];
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);        
            }
        }
        return dp[n][m];
    }
};