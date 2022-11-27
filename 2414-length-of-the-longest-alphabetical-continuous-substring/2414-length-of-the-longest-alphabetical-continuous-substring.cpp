class Solution {
public:
    int longestContinuousSubstring(string s) {
        int res = 1 , mx=1;
        int n  = s.length();
        for(int i=1;i<n;i++)
        {
            if((s[i]-s[i-1]) == 1)
            {
                mx++;
                res = max(mx, res);
            }
            else mx = 1;
        }
        return res;
    }
};