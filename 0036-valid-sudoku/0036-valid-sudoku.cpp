class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int N = board.size();
        unordered_set<char>rowset[N],colset[N],boxset[N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                int boxno = (i/3)*3+(j/3);
                char val = board[i][j];
                if(val=='.')
                    continue;
                if(rowset[i].count(val) || colset[j].count(val) || boxset[boxno].count(val))
                    return false;
                rowset[i].insert(val);
                colset[j].insert(val);
                boxset[boxno].insert(val);
            }
        }
        return true;
    }
};