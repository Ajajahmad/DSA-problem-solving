class Solution {
public:
    bool solve(vector<vector<char>>& board, string &word , int i, int j, int s)
    {
        int n =board.size(), m = board[0].size();
        if(s>=word.size() ) return true;
        if(  i<0 || j<0 || i>=n || j>=m || board[i][j]!=word[s]) return false;
        char ch = board[i][j];
         board[i][j] = '.';
        bool flag = solve(board , word, i+1,j,s+1) || solve(board , word, i,j+1,s+1) ||solve(board , word, i-1,j,s+1)||solve(board , word, i,j-1,s+1);
        
        
         board[i][j] = ch;
        return flag;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n =board.size(), m = board[0].size();
        
        for( int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(solve(board , word, i,j, 0))
                    return true;
            }
        }
        return false;
    }
    
    
};