class Solution {
public:
    int dp[73][73][73];
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n= grid.size() , m = grid[0].size();
        memset(dp , -1, sizeof(dp));
        int ans = solve( 0, 0,  m-1, grid);
        if(ans<0) return 0;
        return ans;
    }
    int solve(int r1 , int c1, int c2 ,vector<vector<int>> &grid)
    {
        int n= grid.size() , m = grid[0].size();
        if(r1>=n  || c1<0 || c2<0 || c1>=m || c2>=m ||  grid[r1][c1]==-1 || grid[r1][c2]==-1) return INT_MIN;
        
        if(r1==n-1)
        {
            if(c1==c2) return grid[r1][c1];
            else return grid[r1][c1] + grid[r1][c2];
         
        }
        
        if(dp[r1][c1][c2]!=-1) return dp[r1][c1][c2];
        
        int ch = 0;
        if( c1==c2) ch+= grid[r1][c1];
        else ch+= grid[r1][c1] + grid[r1][c2];
        int f1 = INT_MIN;
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                f1 = max(f1 , solve(r1+1 , c1+i , c2+j , grid));
            }
        }
        
        return  dp[r1][c1][c2]= ch+f1;
    }
};