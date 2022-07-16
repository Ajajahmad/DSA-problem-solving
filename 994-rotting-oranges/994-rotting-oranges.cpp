class Solution {
public:
    vector<pair<int , int>> dir{ {1,0},{-1,0},{0,1},{0,-1} };
    
    int res=0;
    queue<pair<int,int>> q;
        
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m= grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j =0 ;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    
                     q.push({i,j});
                    
                }
            }
        }
        solve(grid );
        
        
         for(int i=0;i<n;i++)
        {
            for(int j =0 ;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                    
                }
            }
        }
        return res;
        
    }
    void solve(vector<vector<int>>& grid)
    {
        int n=grid.size(), m= grid[0].size();
        
        
        while(!q.empty())
        {
            int count=0;
            int sz= q.size();
            while(sz!=0)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                grid[x][y]= -1;

                for(int k=0;k<4;k++)
                {
                    int row = x+dir[k].first;
                    int col = y+dir[k].second;
                    if(row>=0 && col>=0 && row<n && col<m && grid[row][col]==1)
                    {
                        grid[row][col] =2;
                        q.push({row , col});
                        if(count==0)
                        {
                            res++;
                            count=1;
                        }

                    }
                }
                sz--;
                
                
            }
            
            
            
        }
    }
};