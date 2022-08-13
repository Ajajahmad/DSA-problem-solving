class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum =0 ;
        int n = nums.size();
        for(int i=0;i<n;i++) sum+= nums[i] ;
        if(sum%2!=0) return false;
        
        sum = sum/2;
        int dp[n+1][sum+1];
        for(int i=0;i<n+1;i++)  dp[i][0]= true;
         for(int i=0;i<sum+1;i++)  dp[0][i]= false;
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(j<nums[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][sum];
    }
};