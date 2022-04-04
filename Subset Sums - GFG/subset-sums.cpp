// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void solve(vector<int> a, int n, int i ,vector<int> &res,int sum=0)
    {
        if(i==n)
        {
            res.push_back(sum);
            return;
        }
        solve(a, n , i+1 , res, sum+a[i]);
        solve(a, n , i+1 , res, sum);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> res;
        solve(arr , N, 0 , res,0);
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
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends