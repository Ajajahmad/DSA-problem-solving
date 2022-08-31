class Solution {
public:
    vector<int> getRow(int r) {
        vector<int> curRow;
        curRow.push_back(1);
        if(r==0) return curRow;
        int a, b;
        for(int i=1;i<=r;i++)
        {
            
            
            for(int j=0;j<=i;j++)
            {
                 
                if(j==0 )
                {
                    a = curRow[0];
                    curRow[j] = 1;
                }
                else if(j==i)
                {
                    curRow.push_back(1);
                }
                else
                {
                    b = curRow[j];
                    
                    curRow[j] = (a+b);
                    a = b;
                }
            }
            
        }
        return curRow;
    }
};