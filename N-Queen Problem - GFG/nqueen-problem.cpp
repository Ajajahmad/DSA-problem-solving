// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
 bool isSafe(int row , int col, vector<string>& board,int n)
    {
        int dupr=row;
        int dupc=col;
        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q') return false;
               row--;
               col--;
        }
        row = dupr;
        col = dupc;
        while(col>=0)
       {
           if(board[row][col]=='Q') return false;
           col--;
       }
       row = dupr;
        col = dupc;
        while(col>=0 && row<n)
       {
           if(board[row][col]=='Q') return false;
           col--;
           row++;
       }
        return true;
    }
    void solve(int col, vector<string> &board ,vector<vector<int>>&res ,vector<int>&ds, int n)
    {
        if(col==n)
        {
            res.push_back(ds);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,board,n))
            {
                board[row][col]='Q';
                ds.push_back(row+1);
                solve(col+1,board,res,ds,n);
                ds.pop_back();
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
         vector<vector<int>> res;
         vector<int>ds;
        vector<string> board(n);
        string str(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=str;
        }
        solve(0 , board ,res ,ds, n);
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends