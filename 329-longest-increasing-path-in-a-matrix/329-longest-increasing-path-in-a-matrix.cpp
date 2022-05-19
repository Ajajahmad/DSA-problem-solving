class Solution {
public:
    int res = 0;
    int n , m;
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
         n = matrix.size();
       m = matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        for(int  i = 0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[i][j]= solve(matrix , i, j ,dp);
                res = max(res,dp[i][j]);
            }
        }
        return res;
    }
    int solve(vector<vector<int>>& matrix , int i, int j,vector<vector<int>>&dp)
    {
        if(i<0 || i>=n || j<0 || j>=m) return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int op1=1,op2=1,op3=1,op4=1;
        int  value = matrix[i][j];
        if(j<m-1 && matrix[i][j+1]>value )
            op1 =1+ solve(matrix , i, j+1,dp);
        if(j>0 && matrix[i][j-1]>value )
            op2=1+solve(matrix , i, j-1,dp);
        if(i<n-1 &&matrix[i+1][j]>value )
            op3=1+solve(matrix , i+1, j,dp);
        if(i>0 && matrix[i-1][j]>value )
            op4=1+solve(matrix , i-1, j,dp);
        dp[i][j]=max(op1,max(op2,max(op3,op4)));
        return dp[i][j];
    }
};