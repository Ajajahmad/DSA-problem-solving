class Solution {
public:
        int dp[53][53][53][53];
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        memset(dp , -1 , sizeof(dp));
        int ans =  solve( 0 , 0 , 0, 0 ,grid);
        if(ans < 0) return 0;
        return ans;
    }
    int solve(int r1, int c1 , int r2, int c2 , vector<vector<int>>& grid)
    {
        int n= grid.size();
        if(r1>=n || r2>=n  || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2] == -1) return INT_MIN;
        
        if(r1==n-1 && c1==n-1)
        {
            return grid[r1][c1];
        }
        else if(r2 == n-1 && c2==n-1) return grid[r2][c2];
        
        if(dp[r1][c1][r2][c2]!=-1) return dp[r1][c1][r2][c2];
        
        int ch = 0;
        if(r1== r2 && c1==c2)
        {
            ch += grid[r1][c1];
        }
        else{
            ch += grid[r1][c1] + grid[r2][c2];
        }
        //h , h
        int f1 = solve(r1 , c1+1, r2, c2+1 , grid);
        // v,v,
        int f2  = solve(r1+1 , c1 ,r2+1, c2 ,grid);
        //v,h
        int f3 = solve(r1+1 , c1, r2 , c2+1 , grid);
        // h,v
        int f4 = solve(r1 , c1+1,r2+1 , c2 , grid);
        
        ch += max(max(f1, f2) , max(f3, f4));
        
        
        return dp[r1][c1][r2][c2] = ch;
    }
};