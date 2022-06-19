class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num==0) return 0;
        if(k>num) return -1;
        int sum=k;
        if(k==0)
        {
            if(num%10==0) return 1;
            else return -1;
        }
        vector<int>temp;
        while(sum<=num)
        {
            temp.push_back(sum) ;
            sum+=10;
        }
        return coinChange(temp , num);
    }
    int coinChange(vector<int>& coins, int sum) {
        int n = coins.size();
        int dp[n+1][sum+1];
        for(int i=0;i<n+1;i++) dp[i][0]=0;
        for(int i=0;i<sum+1;i++) dp[0][i] = INT_MAX-1;
        for(int i=1;i<sum+1;i++)
        {
            if(i%coins[0]==0) dp[1][i] = i/coins[0];
            else dp[1][i] = INT_MAX-1;
        }
        
        for(int i=2;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(coins[i-1]<=j)
                    dp[i][j] = min(dp[i-1][j], 1+ dp[i][j-coins[i-1]]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        int value = dp[n][sum];
        if(value==INT_MAX || value==INT_MAX-1) return -1;
        else return value;
    }
};