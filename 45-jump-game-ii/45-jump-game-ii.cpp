class Solution {
public:
    int dp[100001];
    int jump(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return 0;
        memset(dp , -1, sizeof(dp));
        
        return solve(nums,0);
    }
    int solve(vector<int>&nums , int i)
    {
        int n= nums.size();
        if(i>=n-1) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int ans = INT_MAX-1;
        for(int j=i+1;j<=nums[i]+i;j++)
        {
            
            ans = min(ans , 1+solve(nums,j));
        }
        return dp[i] = ans;
    }
};