class Solution {
public:
    int dp[1006];
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(dp , -1, sizeof(dp));
        
        return min( solve(cost, 0) , solve(cost,1) );
    }
    
    int solve(vector<int>&cost , int i)
    {
        int n = cost.size();
        if(i>=n)
        {
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        return dp[i] = cost[i] + min(solve(cost,i+1) , solve(cost,i+2));
    }
};