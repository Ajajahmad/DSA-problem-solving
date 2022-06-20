class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        if(target==mat) return true;
        
        for(int k=0;k<3;k++)
        {
            vector<vector<int>> temp(n,vector<int>(n));
            int x=0,y=0;
            for(int j=0;j<n;j++)
            {
                y=0;
                for(int i=n-1;i>=0;i--)
                {
                    int val = mat[i][j];
                    temp[x][y] = val;
                    y++;
                }
                x++;
            }
            if(target == temp) return true;
            mat = temp;
        }
        return false;
        
    }
};