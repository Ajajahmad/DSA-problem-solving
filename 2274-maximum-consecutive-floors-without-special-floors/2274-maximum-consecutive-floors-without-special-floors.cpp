class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& sp) {
        sort(sp.begin(),sp.end());
        int res=0;
        top++;
        bottom--;
        int pre = bottom;
        for(int i=0;i<sp.size();i++)
        {
            int count = sp[i]-pre-1;
            res = max(res, count);
            pre = sp[i];
        }
        int count =top-pre-1;
        res = max(res, count);
        return res;
    }
};