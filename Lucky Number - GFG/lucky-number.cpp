// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int isLuckyOrNot(long long N) {
       unordered_map<int,int>mp;
       
       if (N==1)
           return 1;
       
       int x;
       while(N>0){
           
           x = N%10;
           mp[x]++;
           
           if(mp[x]>1 or mp[1]>0)
               return 0;
           
           N/=10;
       }
       
       return 1;


    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isLuckyOrNot(N) << endl;
    }
    return 0;
}  // } Driver Code Ends