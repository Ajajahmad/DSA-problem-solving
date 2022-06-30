class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==0 || (trust.size()==0 && n!=1)) return -1;
        if(trust.size()==0 && n==1) return 1;
        
        vector<int>adj[n+1];
        for(int i=0;i<trust.size();i++){
            adj[trust[i][0]].push_back(trust[i][1]);
        }
        map<int, int> mp;
        for(int i=0;i<trust.size();i++)
            mp[trust[i][1]]++;
        for(auto it:mp)
            if(it.second==n-1 && adj[it.first].size()==0)
                return it.first;
        return -1;
    }
};