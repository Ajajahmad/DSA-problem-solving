class Solution {
public:
    int dp[100001];
    bool canReach(vector<int>& arr, int start) {
        memset(dp, -1, sizeof(dp));
        return solve(arr, start);
    }
    bool solve(vector<int>& arr, int start)
    {
        int n = arr.size();
        if(start>=n || start<0 || arr[start]<0) return false;
        if(arr[start]==0) return true;
        if(dp[start]!=-1) return dp[start];
        
        return dp[start] =(arr[start] = -arr[start]) && (solve(arr,start-arr[start]) || solve(arr,start+arr[start]));
    }
    
};