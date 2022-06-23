class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for(int i=0;i<pre.size();i++)
            adj[pre[i][0]].push_back(pre[i][1]);
        
        vector<int> vis(n,0);
        vector<int> dfsvis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(checkCycle(i, adj , vis,dfsvis))
                    return false;
            }
        }
        return true;
    }
    
    bool checkCycle(int node ,vector<vector<int>>& adj , vector<int> &vis, vector<int> &dfsvis ){
        vis[node] = 1;
        dfsvis[node] =1;
        for(int i=0;i<adj[node].size() ; i++ )
        {
            int  it = adj[node][i];
            if(!vis[it])
            {
                if(checkCycle(it ,adj, vis ,dfsvis))
                    return true;
            }
            else if(dfsvis[it])
                    return true;
            
        }
        dfsvis[node]= 0;
        return false;
    }
}; 