// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool isOK(int node , int col , bool graph[101][101] , int color[] , int m ,int n)
{
    for(int k=0;k<n;k++)
    {
        if(node!=k && graph[k][node]==1 && color[k]==col) return false;
    }
    return true;
}

bool solve(int node , bool graph[101][101], int color[] ,int m ,int n)
{
    if(node==n) return true;
    for(int i=1;i<=m;i++)
    {
        if(isOK(node , i , graph ,color, m,n))
        {
            color[node]=i;
            if(solve(node+1, graph, color, m, n))
                return true;
            color[node]=0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int N)
{
    int color[N]={0};
    if(solve(0 , graph, color, m ,N)) return true;
    else return false;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends