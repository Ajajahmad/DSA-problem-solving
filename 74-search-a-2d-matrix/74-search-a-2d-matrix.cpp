class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i =1;
        int n  = matrix.size(),m=matrix[0].size();
        while(i<n && matrix[i][0]<=target)
        {
            i++;
        }
        i--;
        for(int j=0;j<m;j++)
            if(matrix[i][j]==target) return true;
        return false;
    }
};