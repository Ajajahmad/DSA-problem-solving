class Solution {
public:
    int mod = 1e9+7;
    int dp[1001][31];
    int helper(int n , int k , int target , int sum)
    {
        
        if(n == 0 and sum == target)
            return 1;
        if (n == 0)return 0;
        if(dp[sum][n]!=-1)
            return dp[sum][n];
        long long cnt = 0;
        for(int i = 1 ;i<=k;i++ )
        {
            if(sum + i > target)break;
            cnt += helper(n-1 , k , target , sum+i);
            
        }
        return dp[sum][n] =  cnt%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp , -1 , sizeof dp);
        return helper(n , k , target , 0);
    }
};