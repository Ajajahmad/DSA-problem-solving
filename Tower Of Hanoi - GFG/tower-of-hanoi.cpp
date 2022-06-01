// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long ans=0;
    long long toh(int N, int from, int to, int aux) {
        solve(N, from , to, aux);
        return ans;
    }
    void solve(int N , int s,int d, int h)
    {
        if(N==0) return;
        
        
        solve(N-1, s,h,d);
        cout<<"move disk "<<N<<" from rod "<<s<<" to rod "<<d<<endl;
        ans++;
        solve(N-1,h,d,s);
    }

};

// { Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}


//Position this line where user code will be pasted.  // } Driver Code Ends