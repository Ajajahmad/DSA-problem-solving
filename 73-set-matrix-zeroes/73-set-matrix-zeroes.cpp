class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row =matrix.size();
        int col = matrix[0].size();
        bool isRow = false, isCol =false;
        
        for(int r=0;r<row;r++)
        {
            for(int c=0;c<col;c++)
            {
                if(r==0 && matrix[r][c]==0) isCol = true;
                if(c==0 && matrix[r][c] == 0) isRow = true;
                if(matrix[r][c]==0) 
                {
                    matrix[r][0]=0;
                    matrix[0][c] =0;
                }
            }
        }
        
        for(int i=1;i<row;i++)
        {
            if(matrix[i][0]==0)
            {
                for(int j=1;j<col;j++) matrix[i][j]=0;
            }
        }
        for(int j=1;j<col;j++)
        {
            if(matrix[0][j]==0)
            {
                for(int i=1;i<row;i++) matrix[i][j]=0;
            }
        }
        if(isRow == true)
        {
            for(int i=0;i<row;i++) matrix[i][0]= 0;
        }
        if(isCol == true )
        {
            for(int i=0;i<col ; i++) matrix[0][i] =0 ;
            
        }
    }
};