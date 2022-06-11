class Solution {
public:
    int dp[201][10001];
    int superEggDrop(int n, int k) {
         memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
    int solve(int e , int f)
    {
        if(f==0 || f==1) return f;
        if(e==1) return f;
        if(dp[e][f]!=-1) return dp[e][f];
        int mn = INT_MAX;
        int l=1,r= f;
        while(l<=r){
            int k = l+ (r-l ) /2;
            int low,high;
            if(dp[e-1][k-1]!=-1) low=dp[e-1][k-1];
            else
            {
                low = solve(e-1,k-1);
                dp[e-1][k-1] = low;
            }
            if(dp[e][f-k]!=-1) high=dp[e][f-k];
            else
            {
                high = solve(e,f-k);
                dp[e][f-k] = high;
            }
            int temp = 1+ max(low , high);
            if (low<high)  
                l=k+1;
            else
                r=k-1;
            mn = min(temp , mn);
        }
        return dp[e][f] = mn;
    }
};