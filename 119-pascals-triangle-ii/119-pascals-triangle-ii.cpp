class Solution {
public:
    vector<int> getRow(int r) {
        vector<int> pre;
        pre.push_back(1);
        if(r==0) return pre;
        vector<int> curRow;
        for(int i=1;i<=r;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i)
                {
                    curRow.push_back(1);
                }
                else
                {
                    curRow.push_back(pre[j-1] + pre[j]);
                }
            }
            pre = curRow;
            curRow.clear();
        }
        return pre;
    }
};