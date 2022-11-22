class Solution {
public:
    int solve(vector<int> &pers , int i, int sum,vector<vector<int>> &dp)
    {
        if(sum==0) return 0;
        if(i<0) return 1e5;
        if(dp[i][sum]!=-1) return dp[i][sum];
        int a = INT_MAX, b=INT_MAX;
        if(pers[i]<=sum)
             a = 1+solve(pers , i ,sum-pers[i],dp);
        b= solve(pers , i-1,sum,dp);
        return dp[i][sum]=min(a,b);
    }
    int numSquares(int n) {
        vector<int> pers;
        for(int i=1;i<=n;i++)
        {
            if(i*i<=n) pers.push_back(i*i);
            else break;
        }
        
        int sz= pers.size();
        // cout<<sz;
        vector<vector<int>> dp(sz+1,vector<int>(n+1 ,-1));
        return solve(pers, sz-1, n , dp);
    }
};