class Solution {
public:
    int dp[301][301];
       int solve(int i,int j,vector<int>& nums)
       {
           int n=nums.size();
           if(i>j)
           {
               return 0;
           }
           if(dp[i][j]!=-1)
           {
               return dp[i][j];
           }
           int ans=INT_MIN;
           for(int k=i;k<=j;k++)
           {
               int temp=(i>0?nums[i-1]:1)*nums[k]*((j+1)<n?nums[j+1]:1);
               ans=max(ans,temp+solve(i,k-1,nums)+solve(k+1,j,nums));
           }
           return dp[i][j]=ans;
       }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,n-1,nums);
        return ans;
    }
};