class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
         int n = inter.size();
        if(n==1) return inter;
        vector<vector<int>> res;
        sort(inter.begin() , inter.end()) ;
        int first = inter[0][0], last = inter[0][1];
        for(int i=1;i<n;i++)
        {
            if(last<inter[i][0])
            {
                res.push_back({first , last});
                first = inter[i][0] ;
                last = inter[i][1];
            }
            else
            {
                last = max(last , inter[i][1]);
            }
        }
        res.push_back({first , last});
        return res;
    }
};