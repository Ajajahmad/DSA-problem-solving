class Solution {
public:
    int dp[110];
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        memset(dp,-1,sizeof(dp));
        
        return solve(nums, 0);
        
    }
    int solve(vector<int>&nums, int i)
    {
        int n = nums.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(nums[i]+solve(nums,i+2) , solve(nums,i+1));
    }
};