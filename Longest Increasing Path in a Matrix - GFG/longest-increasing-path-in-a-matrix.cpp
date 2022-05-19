// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int res = 0;
    int longestIncreasingPath(vector<vector<int>>& matrix, int n, int m) {
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        for(int  i = 0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[i][j]= solve(matrix , i, j ,dp);
                res = max(res,dp[i][j]);
            }
        }
        return res+1;
    }
    int solve(vector<vector<int>>& matrix , int i, int j,vector<vector<int>>&dp)
    {
       int  n = matrix.size();
       int m = matrix[0].size();
        if(i<0 || i>=n || j<0 || j>=m) return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int op1=0,op2=0,op3=0,op4=0;
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

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends