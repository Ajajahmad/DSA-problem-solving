// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i , int j ,vector<vector<int>> &m, vector<vector<int>> &vis, vector<string> &res , string ds , int n)
    {
        if(i==n-1 &&j==n-1)
        {
            res.push_back(ds);
            return;
        }
        if(i+1<n && vis[i+1][j]!=1 && m[i+1][j]==1)
        {
            vis[i][j]=1;
            ds.push_back('D');
            solve(i+1, j, m , vis , res, ds,n);
            ds.pop_back();
            vis[i][j]=0;
        }
        if(j+1<n && vis[i][j+1]!=1 && m[i][j+1]==1)
        {
            vis[i][j]=1;
            ds.push_back('R');
            solve(i, j+1, m , vis , res, ds,n);
            ds.pop_back();
            vis[i][j]=0;
        }
        if(i-1>=0 && vis[i-1][j]!=1 && m[i-1][j]==1)
        {
            vis[i][j]=1;
            ds.push_back('U');
            solve(i-1, j, m , vis , res, ds,n);
            ds.pop_back();
            vis[i][j]=0;
            
        }
         if(j-1>=0 && vis[i][j-1]!=1 && m[i][j-1]==1)
        {
            vis[i][j]=1;
            ds.push_back('L');
            solve(i, j-1, m , vis , res, ds,n);
            ds.pop_back();
            vis[i][j]=0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
        if(m[0][0]==0 || m[n-1][n-1]==0) return res;
        vector<vector<int>> vis;
        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            for(int j=0;j<n;j++)
                temp.push_back(0);
            vis.push_back(temp);
        }
        string ds="";
        solve( 0 ,0, m ,vis,res , ds ,n );
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends