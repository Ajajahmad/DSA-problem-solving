class Solution {
public:
    bool canPartition(vector<int>& a) {
        int n = a.size();
        int sum = 0;
        for(int i=0;i<n;i++) sum+=a[i];
        if(sum%2!=0) return 0;
        sum=sum/2;
        int dp[n+1][sum+1];
        for(int j=0;j<sum+1;j++) dp[0][j]=false;
        for(int j=0;j<n+1;j++) dp[j][0]=true;
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(a[i-1]<=j)
                    dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
            
        }
        return dp[n][sum];
    }
};