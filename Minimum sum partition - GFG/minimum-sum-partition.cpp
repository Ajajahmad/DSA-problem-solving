// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int a[], int n)  { 
	    int range=0;
	    for(int i =0;i<n;i++) range+=a[i];
	    int dp[n+1][range+1];
	    for(int i=0;i<range+1;i++) dp[0][i] = 0;
	    for(int i=0;i<n+1;i++) dp[i][0] =1;
	    
	    for(int i=1;i<n+1;i++)
	    {
	        for(int j=1;j<range+1;j++)
	        {
	            if(a[i-1]<=j)
	                dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
	            else
	                dp[i][j] = dp[i-1][j];
	        }
	    }
	    int res =INT_MAX;
	    for(int i=0;i<=(range)/2;i++)
	    {
	        if(dp[n][i]==1)
	             res = min(res ,range-2*i );
	        
	    }
	    return res;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends