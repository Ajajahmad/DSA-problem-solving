class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
         int n=text1.length();
        int m=text2.length();
        int dp[n+1][m+1];
        for(int i=0;i<n+1;i++) dp[i][0] = 0;
        for(int i=0;i<m+1;i++) dp[0][i] = 0;
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                 if(text1[i-1]==text2[j-1])
                     dp[i][j] = 1+dp[i-1][j-1];
                else
                {
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        
        
        string res = "";
        int i=n, j=m;
        while(i>0 && j>0)
        {
            if(text1[i-1] == text2[j-1])
            {
                // cout<<text1[i-1];
                res.push_back(text1[i-1]);
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j] > dp[i][j-1])
                {
                    
                    i--;

                }
                else
                {
                   
                    j--;
                }
            }
        }
        reverse(res.begin() , res.end());
        if(res=="") cout<<"FUCK U ";
        cout<<res<< " ";
        return dp[n][m];
    }
};