// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void MakeZeros(vector<vector<int> >& mat) {
        vector<vector<int> > matrix = mat;
        vector<pair<int,int>> temp;
        int n=matrix.size();
        int m= matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0) temp.push_back({i,j});
            }
        }
        
        for(int i=0;i<temp.size();i++)
        {
            int row = temp[i].first;
            int col = temp[i].second;
            solve(matrix ,mat , row, col);
        }
        mat = matrix;
    }
    void solve(vector<vector<int>>& matrix, vector<vector<int>>& mat , int row , int col)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int value=0;
        if(row-1>=0) {
            value += mat[row-1][col];
            matrix[row-1][col]=0;
        }
        if(col-1>=0) {
            value += mat[row][col-1];
            matrix[row][col-1]=0;
        }
        if(row+1<n){
            value += mat[row+1][col];
            matrix[row+1][col]=0;
        }
        if(col+1<m) {
            value+= mat[row][col+1];
            matrix[row][col+1] =0;
        }
        matrix[row][col]= value;
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.MakeZeros(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends