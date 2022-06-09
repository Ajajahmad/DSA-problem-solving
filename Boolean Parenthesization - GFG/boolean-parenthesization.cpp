// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    unordered_map<string,int> mp;
    int mod = 1003;
    int countWays(int N, string S){
        mp.clear();
        return solve(S,0,N-1,true);
    }
    int solve(string s, int i , int j , bool isTrue)
    {
        if(i>j) return 0;
        if(i==j)
        {
            if(isTrue==true) return s[i]=='T';
            else return s[i]=='F';
        }
        string temp= to_string(i);
        temp.append(" ");
        temp += to_string(j);
        temp.append(" ");
        temp += to_string(isTrue);
        if(mp.find(temp)!=mp.end())
            return mp[temp];
        
        int ans= 0;
        for(int k=i+1;k<=j-1;k=k+2)
        {
            int lt = solve(s,i,k-1,true);
            int lf = solve(s,i,k-1,false);
            int rt = solve(s,k+1,j,true);
            int rf = solve(s,k+1,j,false);
            if(s[k]=='&')
            {
                if(isTrue==true)
                    ans += (lt*rt)%mod;
                else
                    ans += (lt*rf)%mod + (lf*rt)%mod + (lf*rf)%mod;
            }
            else if(s[k]=='|')
            {
                if(isTrue==true)
                    ans += (lt*rt)%mod + (lt*rf)%mod + (lf*rt)%mod;
                else
                    ans += (rf*lf)%mod;
            }
            else if(s[k]=='^')
            {
                if(isTrue==true)
                    ans += (lf*rt)%mod +(rf*lt)%mod;
                else
                    ans += (lt*rt)%mod + (rf*lf)%mod;
            }
        }
        return mp[temp] = ans%mod;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends