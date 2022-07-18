class Solution {
public:
    double average(vector<int>& salary) {
        int mn=INT_MAX, mx = INT_MIN;
        int sum=0;
        for(int i=0;i<salary.size();i++)
        {
            sum+=salary[i];
            mn = min(mn,salary[i]);
            mx = max(mx , salary[i]);
        }
        
        int n= salary.size();
        if(mx==mn)
        {
            sum = sum-mx;
            return (double)sum/(n-1);
        }
        sum = sum - mx - mn;
        return (double)sum/(n-2);
    }
};