class Solution {
public:
    int dp[601][101][101];
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<int> one, zero;
        for(int i=0;i<strs.size() ;i++)
        {
            int o=0, z=0;
            string s = strs[i];
            for(int j=0;j<s.size() ;j++)
            {
                if(s[j]=='0') z++;
                else o++;
            }
            one.push_back(o);
            zero.push_back(z);
        }
        memset(dp, -1, sizeof(dp));
        
       return solve(strs , strs.size()-1 , m, n, one, zero);
        
    }
    int solve(vector<string> &strs, int i, int m , int n,  vector<int> &one,  vector<int> &zero)
    {
        if(i<0)
        {
            return 0;
        }
        
        //pick
        if(dp[i][m][n] !=-1) return dp[i][m][n];
        if(m>=zero[i] && n>=one[i])
            return dp[i][m][n]= max(1+solve(strs, i-1, m-zero[i] , n-one[i] , one, zero)  , solve(strs ,i-1, m, n, one, zero));
        else
            return dp[i][m][n]=solve(strs ,i-1, m, n, one, zero);
            
    }
};