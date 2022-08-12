class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m=n ? grid[0].size() :0 ;
        int ans = 0;
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]!=1)
                {
                     ans++;
                    dfs(i,j,grid, vis);
                   
                }
            }
        }
        return ans;
    }
private:
    void dfs(int i , int j , vector<vector<char>> &grid,vector<vector<int>> &vis)
    {
        int n = grid.size(), m=grid[0].size();
        if(i==n || j==m || i<0 || j<0 ||vis[i][j] ==1 || grid[i][j]=='0') return ;
        
        vis[i][j] = 1;
        dfs(i+1 , j, grid,vis);
        dfs(i , j+1 ,grid,vis);
         dfs(i-1 , j, grid,vis);
        dfs(i , j-1 ,grid , vis);
        
        
    }
};