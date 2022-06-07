// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[101][101];
    int matrixMultiplication(int N, int arr[])
    {
        int i=1,j=N-1;
        memset(dp,-1,sizeof(dp));
        return solve(arr, i , j);
    }
    int solve(int a[] , int i , int j)
    {
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mn = INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            int temp = solve(a,i,k) + solve(a,k+1,j) + (a[i-1]*a[k]*a[j]);
            if(temp<mn) mn = temp;
        }
        return dp[i][j] = mn;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends