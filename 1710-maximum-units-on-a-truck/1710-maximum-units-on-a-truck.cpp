class Solution {
public:
    static bool sortcol(const vector<int>& v1, const vector<int>& v2)
    {
        return v1[1] < v2[1];
    }
    int maximumUnits(vector<vector<int>>& box, int k) {
        sort(box.begin(), box.end() , sortcol);
        int n = box.size();
        int res = 0;
        
        for(int i=n-1;i>=0;i--)
        {
            if(box[i][0]<=k)
            {
                k -= box[i][0];
                res += box[i][0]*box[i][1];
            }
            else
            {
                res += k*box[i][1];
                k=0;
            }
            if(k==0) break;
        }
        return res;
    }
};