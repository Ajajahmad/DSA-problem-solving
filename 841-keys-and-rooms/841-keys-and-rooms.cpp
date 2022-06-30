class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int  n =rooms.size();
        vector<int> vis(n,0);
        
        bfs(rooms, n ,0,vis);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0) return false;
        }
        return true;
    }
    
    void bfs(vector<vector<int>>& rooms , int n ,int node,vector<int> &vis)
    {
        queue<int> q;
        q.push(node);
        vis[node] =1;
        while(!q.empty())
        {
            int val = q.front();
            q.pop();
            for(auto it:rooms[val])
            {
                if(!vis[it])
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
};