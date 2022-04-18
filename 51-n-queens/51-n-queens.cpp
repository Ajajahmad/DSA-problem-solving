class Solution {
public:
    bool valid(vector<string> &board , int i , int j,int n)
    {
        int k=i, l=j;
        while(k>=0)
        {
            if(board[k][j]=='Q') 
                return false;
            k--;
        }
        k=i;
        while(l>=0)
        {
            if(board[i][l]=='Q') return false;
            l--;
        }
        l=j;
        while(k>=0 && l>=0)
        {
            if(board[k][l]=='Q') return false;
            k--;
            l--;
        }
        k=i;
        l=j;
        while(k<n && l>=0)
        {
            if(board[k][l]=='Q') return false;
            k++;
            l--;
        }
        return true;
    }
        
        
    void solve(int j , int n ,vector<string>& board ,vector<vector<string>>&res )
    {
        if(j==n)
        {
            res.push_back(board);
            return;
        }
        for(int i=0;i<n;i++)
        {
            
            if(valid(board,i,j,n))
            {
                board[i][j]='Q';
                 solve(j+1 , n ,board ,res);
                board[i][j]='.';
            }
            
               
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        vector<vector<string>> res;
            solve(0,n,board, res);
        return res;
    }
};