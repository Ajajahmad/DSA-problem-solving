class Solution {
public:
    bool isSafe(int row , int col, vector<string>& board,int n)
    {
        int dupr=row;
        int dupc=col;
        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q') return false;
               row--;
               col--;
        }
        row = dupr;
        col = dupc;
        while(col>=0)
       {
           if(board[row][col]=='Q') return false;
           col--;
       }
       row = dupr;
        col = dupc;
        while(col>=0 && row<n)
       {
           if(board[row][col]=='Q') return false;
           col--;
           row++;
       }
        return true;
    }
    void solve(int col, vector<string> &board ,vector<vector<string>>&res , int n)
    {
        if(col==n)
        {
            res.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,board,n))
            {
                board[row][col]='Q';
                solve(col+1,board,res,n);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string str(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=str;
        }
        solve(0 , board ,res , n);
        return res;
    }
};