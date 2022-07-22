class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int res = 0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(i==j || j == mat.size()-i-1)
                    res+= mat[i][j];
            }
        }
        return res;
    }
};