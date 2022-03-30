// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
 int count=0;
  void solve(int a[], int n, int k, int i ,int pro)
  {
      if(i>=n) return;
      if(pro*a[i]<=k) count++;
      if(pro>k) return;
      solve(a,n,k ,i+1, pro);
      solve(a,n,k,i+1, pro*a[i]);
      
  }
    int numOfSubsets(int a[], int n, int k) {
        int pro =1;
        solve(a,n,k,0,pro);
        return count;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>K;

        Solution ob;
        cout << ob.numOfSubsets(arr,N,K) << endl;
    }
    return 0;
}  // } Driver Code Ends