class Solution {
public:
    int mod = 1e9+7;
    int solve(int i , int j , vector<vector<int>> &mat, vector<vector<int>> &v)
    {

        if(i==0 && j==0) return 1;
        if(i<0 || j<0 ) return 0;
        if(mat[i][j]==1) return 0;
        if(v[i][j]!=-1) return v[i][j];
        return  v[i][j] = solve(i-1, j, mat,v) + solve(i, j-1 , mat,v);

    }
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int n = mat.size() , m= mat[0].size();
        if(mat[0][0] == 1) return 0;
        if(n==1&&m==1 && mat[0][0] == 0) return 1;
        vector<vector<int>> v(n+1 , vector<int>(m+1, -1));
        return solve( n-1 , m-1, mat, v);
    }
};