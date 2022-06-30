class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> res;
        vector<int> vis(n,0);
       for(int i=0;i<edges.size();i++)
       {
           vis[edges[i][1]]++;
       }
        for(int i=0;i<n;i++)
        {
            if(vis[i] == 0) res.push_back(i);
        }
        return res;
    }
   
};