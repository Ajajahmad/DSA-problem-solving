class Solution {
public:
    int dp[1001][1001];
    int minimumWhiteTiles(string floor, int n, int l) {
        int sz = floor.length();
        memset(dp,-1,sizeof(dp));
        return solve(floor , sz-1 , n , l);
    }
    int solve(string &floor , int i , int n, int &l)
    {
        
        if(i<0)
        {
            return 0;
        }
        if(dp[i][n]!=-1) return dp[i][n];
            
        if(n<=0)
        {
            if(floor[i]=='1')
                return dp[i][n]=1+solve(floor,i-1,n,l);
            else
                return dp[i][n]=solve(floor , i-1, n, l);
        }
        else
        {
            if(floor[i]=='1')
                return dp[i][n]=min(solve(floor , i-l , n-1, l ) , 1+solve(floor , i-1,n,l));
            else
                return dp[i][n]=min(solve(floor , i-l , n-1, l ) , solve(floor , i-1,n,l));
        }
    }
};