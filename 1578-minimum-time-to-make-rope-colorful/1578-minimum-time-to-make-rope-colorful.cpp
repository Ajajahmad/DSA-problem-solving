class Solution {
public:
    int minCost(string colors, vector<int>& a) {
        int sum = a[0], mx = a[0], n =a.size();
        char ch = colors[0];
        int ans = 0;
        for(int i=1 ; i<n ;i++)
        {
            if(ch == colors[i])
            {
                sum += a[i];
                mx = max(mx , a[i]);
            }
            else
            {
                ans += sum -mx;
                sum = a[i];
                mx = a[i];
                ch = colors[i];
            }
        }
        ans += sum - mx;
        return ans;
    }
};