class Solution {
public:
    int maxProfit(vector<int>& pri) {
        int n = pri.size(),res=0;
        int mx = 1e9;
        for(int i=0;i<n-1;i++)
        {

            mx=min(mx,pri[i]);
            res=max(res,pri[i+1]-mx);
        }
       
        return res;
    }
};