// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int dp[501][501];
    int editDistance(string word1, string word2) {
        int n = word1.length(),m = word2.length();
        memset(dp,-1,sizeof(dp));
        return solve(word1 , word2,n-1,m-1);
    }
    int solve(string word1, string word2 , int i, int j)
    {
        if(i<0 )
            return j+1;
        if(j<0)
            return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j])
            return dp[i][j] = 0+solve(word1,word2, i-1,j-1);
        else 
        {
            return dp[i][j] = 1+min(solve(word1,word2, i-1,j) , min(solve(word1,word2, i-1,j-1), solve(word1,word2, i, j-1)));
        }
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends