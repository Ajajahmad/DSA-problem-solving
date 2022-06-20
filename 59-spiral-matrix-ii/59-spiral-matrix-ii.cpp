class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         int loop = n*n;
        vector<vector<int>> res(n, vector<int>(n,0));
        int count=1;
        int i=0,j=0;
        while(loop>0)
        {
            while(j<n || res[i][j+1]==0)
            {
                res[i][j] = count++;
                loop--;
                if(loop==0 ) break;
                if(j+1==n || res[i][j+1]!=0)
                {
                    i++;
                    break;
                }
                else j++;
            }
            if(loop==0 ) break;
            while(i<n || res[i+1][j]==0)
            {
                res[i][j] = count++;
                loop--;
                if(loop==0 ) break;
                if(i+1==n || res[i+1][j]!=0)
                {
                    j--;
                    break;
                }
                else i++;
            }
            if(loop==0 ) break;
            while(j>=0 || res[i][j-1]==0)
            {
                res[i][j] = count++;
                loop--;
                if(loop==0 ) break;
                if(j-1<0 || res[i][j-1]!=0)
                {
                    i--;
                    break;
                }
                j--;
            }
            if(loop==0 ) break;
            while(i>=0 || res[i-1][j]==0)
            {
                res[i][j] = count++;
                loop--;
                if(loop==0 ) break;
                if(i-1<0 || res[i-1][j]!=0)
                {
                    j++;
                    break;
                }
                i--;
            }
            if(loop==0 ) break;
            
        }
        return res;
            
    }
};