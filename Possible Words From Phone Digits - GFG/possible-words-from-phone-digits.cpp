// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int digits[], int n)
    {
        map<int,string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        vector<string> res;
         if(n==0) return res;
        string ans="";
        solve(digits,ans, res, mp, 0 , n);
        return res;
    }
     void solve(int digits[],string ans,vector<string> &res , map<int,string> &mp, int i, int n )
    {
        if(i==n)
        {
            res.push_back(ans);
            return ; 
        }
        int value = digits[i];
        string str = mp[value];
        for(int j = 0;j<str.length();j++)
        {
            ans.push_back(str[j]);
            solve(digits,ans, res,mp,i+1, n);
            ans.pop_back();
        }
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends