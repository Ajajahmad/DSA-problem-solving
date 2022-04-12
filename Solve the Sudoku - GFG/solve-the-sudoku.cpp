// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool isvalid(int board[N][N], int row , int col ,int ch)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col] == ch) return false;
            if(board[row][i]==ch) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch) return false;
        }
        return true;
    }
    bool SolveSudoku(int board[N][N])  
    { 
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]==0)
                {
                    for(int c=1;c<=9;c++)
                    {
                        if(isvalid(board, i,j, c))
                        {
                            board[i][j]=c;
                            if(SolveSudoku(board)==true) return true;
                            else
                                board[i][j]=0;
                        }
                    }
                     return false;

                }
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int board[N][N]) 
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cout<<board[i][j]<<" ";
            }
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends