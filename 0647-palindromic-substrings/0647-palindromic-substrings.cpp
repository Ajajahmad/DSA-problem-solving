class Solution {
public:
    bool ispal(string s, int i, int j)
    {
        while(i<j )
        {
            if(s[i++]!=s[j--] ) return 0;
        }
        return 1;
    }
    int solve(string s , int i , vector<int> &dp)
    {
        int n = s.length();
        if(i==n) return 0;
        int count = 0;
        if(dp[i]!=-1) return dp[i];
        
        for(int ind =i ;ind<n;ind++){
            if(ispal(s, i ,ind)) count++;
        }
        count += solve(s , i+1, dp);
        return dp[i] = count;
    }
    
    int countSubstrings(string s) {
        int n = s.length();
        cout<<n<< " ";
        vector<int> dp(n ,-1);
        return solve(s, 0, dp);
        
    }
};