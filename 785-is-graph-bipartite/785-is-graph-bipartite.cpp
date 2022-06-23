class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n , -1);
        for(int i=0;i<n;i++){
            if(color[i]==-1)
                if(!bipar(i, graph, color))
                     return false;
        }
        return 1;
        
    }
    bool bipar(int node,vector<vector<int>>& graph , vector<int>& color ){
        queue<int> q;
        q.push(node);
        color[node] =1;
        while(!q.empty()){
            int value = q.front();
            q.pop();
            for(auto it:graph[value]){
                if(color[it]==-1){
                    color[it] = 1 - color[value];
                    q.push(it);
                }
                else if(color[it] == color[value]) return false;
            }
        }
        return true;
    }
};