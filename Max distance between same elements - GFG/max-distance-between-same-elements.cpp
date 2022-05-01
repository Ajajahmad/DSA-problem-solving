// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    // your task is to complete this function
    int maxDistance(int a[], int n)
    {
        map<int, int> mp;
        for(int i=0;i<n;i++)
        {
            mp[a[i]]++;
        }
        int ans  =0;
        for(auto it:mp)
        {
            if(it.second>1)
            {
                int i=0,j=n-1;
                while(a[i]!=it.first) i++;
                while(a[j]!=it.first) j--;
                ans = max(ans , j-i);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.maxDistance(arr,n)<<endl;
    }
    return 0;
}  // } Driver Code Ends