// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int ans = -1e9;
    void f(vector<vector<int>> &a, int i, int j, int n, int m, int xd, int yd, int count) {
        if(i>=n || j>=m || i<0 || j<0 || a[i][j]==0) return;
        if(i==xd && j==yd) ans=max(ans, count);
        a[i][j]=0;
        f(a, i-1, j, n, m, xd, yd, count+1);
        f(a, i+1, j, n, m, xd, yd, count+1);
        f(a, i, j-1, n, m, xd, yd, count+1);
        f(a, i, j+1, n, m, xd, yd, count+1);
        a[i][j]=1;
    }
    int longestPath(vector<vector<int>> a, int xs, int ys, int xd, int yd) {
        int n=a.size(), m=a[0].size(), count=0;
        if(a[xd][yd] == 0) return -1;
        f(a, xs, ys, n, m, xd, yd, count);
        return ans == -1e9 ? -1 : ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends