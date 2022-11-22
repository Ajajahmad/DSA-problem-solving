class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m= grid[0].size() ;
        int ans = 0;
        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]!=1)
                {
                     ans++;
                    bfs(i,j , q, grid , vis);
                   
                }
            }
        }
        return ans;
    }
private:
    void bfs(int i, int j, queue<pair<int,int>> &q,vector<vector<char>>& grid,vector<vector<int>> &vis)
    {
        int n = grid.size(), m= grid[0].size() ;
        q.push({i,j});
        vis[i][j] = 1;
        vector<pair<int,int>> dir{{1,0} , {0,1}, {-1,0},{0,-1}};
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k=0;k<dir.size();k++)
            {
                int i1 = x+dir[k].first;
                int j1 = y+dir[k].second;
                if(i1>=0 && i1<n && j1>=0 && j1<m && grid[i1][j1]!='0' && vis[i1][j1]!=1)
                {
                    vis[i1][j1] = 1;
                    q.push({i1,j1});
                }
            }
        }
    }
};