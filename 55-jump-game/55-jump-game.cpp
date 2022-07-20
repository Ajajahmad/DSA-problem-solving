class Solution {
public:
    bool dp[100001];
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        if(nums[0] == 0) return false;
        memset(dp , true, sizeof(dp));
        return solve(nums , 0);
    }
    
    bool solve(vector<int>&nums , int i)
    {
        if(i>=nums.size()-1) return true;
        
        if(dp[i]==false) return false;
        
        int val = nums[i];
        for(int j=i+1;j<=i+nums[i];j++)
        {
            if(dp[j])
            {
                dp[j] = solve(nums , j);
                if(dp[j])
                    return true;
            }
            
        }
        return false;
    }
};