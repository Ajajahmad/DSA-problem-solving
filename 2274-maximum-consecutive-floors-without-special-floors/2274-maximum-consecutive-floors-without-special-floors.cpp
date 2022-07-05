class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& sp) {
        map<int, int> mp;
        for(int i=0;i<sp.size();i++)
            mp[sp[i]]++;
        int res=0;
        top++;
        bottom--;
        int pre = bottom;
        for(auto it:mp)
        {
            int count = it.first-pre-1;
            res = max(res, count);
            pre = it.first;
        }
        int count =top-pre-1;
        res = max(res, count);
        return res;
    }
};