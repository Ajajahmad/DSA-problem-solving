// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int findTargetSumWays(vector<int>&a ,int target) {
        int s=0;
        int n = a.size();
        for(int i=0;i<n;i++) s+=a[i];
        if((s+target)%2!=0 || s<target ) return 0;
        int sum =( target + s )/2;
        int dp[n+1][sum+1];
        for(int i=0;i<sum+1;i++) dp[0][i]=0;
        for(int i=0;i<n+1;i++) dp[i][0]=1;
        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(a[i-1]<=j)
                    dp[i][j] = dp[i-1][j-a[i-1]] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends