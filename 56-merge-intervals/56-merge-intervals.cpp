class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end());
        int i=0,n= inter.size();
        int start =0,end=0;
        int max;
        vector<vector<int>> res;
        while(i<n)
        {
            start = inter[i][0];
            max= inter[i][1];
            while(i<n-1 && inter[i+1][0]<=max){
                
                 i++;
                if(inter[i][1]>max) max= inter[i][1];
            }
            end= max;
            vector<int> temp;
            temp.push_back(start);
            temp.push_back(end);
            res.push_back(temp);
            i++;
        }
        return res;
    }
};