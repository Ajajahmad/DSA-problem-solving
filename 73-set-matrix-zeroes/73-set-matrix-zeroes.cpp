class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> temp;
        int n=matrix.size();
        int m= matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0) temp.push_back({i,j});
            }
        }
        
        for(int i=0;i<temp.size();i++)
        {
            int row = temp[i].first;
            int col = temp[i].second;
            solve(matrix , row, col);
        }
        
    }
    void solve(vector<vector<int>>& matrix , int row , int col)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = row,j=col;
        while(i>=0)
        {
            matrix[i][j]=0;
            i--;
        }
        i = row,j=col;
        while(j>=0)
        {
            matrix[i][j]=0;
            j--;
        }
        i = row,j=col;
        while(j<m)
        {
            matrix[i][j]=0;
            j++;
        }
         i = row,j=col;
        while(i<n)
        {
            matrix[i][j]=0;
            i++;
        }
    }
};