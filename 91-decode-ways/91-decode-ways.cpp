class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1, -1);
        
        if(s[0]=='0') return 0;
        return solve(s , n ,dp);
    }
    int solve(string s , int n, vector<int>& dp )
    {
        if(n==0)
        {
           
            return 1;
        }
        if(dp[n]!=-1) return dp[n];
        int ans = 0;
        if(n>1)
        {
            int a = s[n-2]-'0', b = s[n-1]-'0';
            if(b>0 && b<27 )
            {
                ans += solve(s , n-1,dp);
            }
            int c= a*10 +b;
            if(c>0 && c<27 && a!=0)
            {
                ans += solve(s, n-2,dp);
            }
        }
        else if(n==1)
        {
            int a= s[n-1] - '0';
            if(a>0 && a<27) ans+= solve(s , n-1,dp);
        }
        return dp[n]=ans ;
    }
};
