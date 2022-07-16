class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        if(n==0) return mat;
        int m = mat[0].size();
        
        vector<pair<int,int>> dir(4);
        dir[0]={1,0};
        dir[1]={-1,0};
        dir[2]={0,1};
        dir[3]={0,-1};
        
        
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                    q.push({i,j});
                else
                    mat[i][j]=-1;
            }
        }
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<dir.size();i++)
            {
                int row = x+dir[i].first;
                int col = y+dir[i].second;
                if(row>=0 && col>=0 && row<n && col<m && mat[row][col]<0)
                {
                    q.push({row,col});
                    mat[row][col] = 1+ mat[x][y];
                }
            }
        }
        return mat;
    }
};