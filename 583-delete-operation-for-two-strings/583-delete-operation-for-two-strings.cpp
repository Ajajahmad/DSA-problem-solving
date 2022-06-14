class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1= word1.length() , n2 = word2.length();
        int l  = lcs(word1,word2);
        return n1-l + n2-l;
    }
    int lcs(string word1, string word2)
    {
        int n= word1.length() , m = word2.length();
        int dp[n+1][m+1];
        for(int i=0;i<n+1;i++) dp[i][0] = 0;
        for(int i=0;i<m+1;i++) dp[0][i] = 0;
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(word1[i-1]==word2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        
        cout<<dp[n][m];
        return dp[n][m];
    }
};