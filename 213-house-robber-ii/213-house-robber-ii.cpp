class Solution {
public:
    int dp[101][2];
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        memset(dp,-1,sizeof(dp));
        
        return solve(nums,0,false);
    }
    
    int solve(vector<int>&nums , int i , int flag)
    {
        int n = nums.size();
        if(i>=n) return 0;
        if(dp[i][flag]!=-1) return dp[i][flag];
        
        if(i==n-1 && flag==true) return 0;
        
        if(i==0)
        {
            return dp[i][flag]= max(nums[i]+solve(nums,i+2,true) , solve(nums,i+1,flag));
        }
        return dp[i][flag]= max(nums[i]+solve(nums,i+2,flag),solve(nums,i+1,flag));
    }
};