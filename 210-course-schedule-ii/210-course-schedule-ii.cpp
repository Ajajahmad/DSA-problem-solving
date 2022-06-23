class Solution {
public :
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for(int i=0;i<pre.size();i++)
            adj[pre[i][1]].push_back(pre[i][0]);
        vector<int> res;
        
        queue<int>q;
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
                int it = adj[i][j];
                indegree[it]++;
            }
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(int i=0;i<adj[node].size();i++){
                int it = adj[node][i];
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        
       if(res.size()==n)
           return res;
        else
        {
            return {};
        }
        
    }
   
    
    
};