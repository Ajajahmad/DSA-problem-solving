class Solution {
public:
    int mod = 1e9+7;;
    long long dp[1000001];
    long long count(int i , int z, int o)
    {
        if(i<0) return 0;
        if(i==0) return 1;
        if(dp[i]!=-1) return dp[i];
        long long  a = count(i-z , z, o);
        long long b = count(i-o, z, o);
        return dp[i]  = (a%mod+b%mod)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp, -1, sizeof(dp));
        long long res = 0;
        for(int i = low ; i<=high ;i++)
        {
           res = (res%mod + count(i, zero ,one)%mod)%mod;
            
            
        }
        return res;
    }
};