class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& a, vector<int>& queries) {
        vector<int> q= queries, res;
        sort(a.begin() , a.end());
        sort(q.begin() , q.end());
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int i=0,j=0;
        for(j=0;j<q.size();j++)
        {
            int que = q[j];
            while(i<a.size() && a[i][0]<=que)
            {
                int left = a[i][0];
                int right = a[i][1];
                pq.push({right-left+1, right});
                i++;
            }
            while(!pq.empty() && pq.top().second< que)
            {
                pq.pop();
            }
            if(!pq.empty())
            {
                mp[que] = pq.top().first;
            }
            else
            {
                mp[que] = -1;
            }
        }
        for(i=0;i<queries.size() ; i++)
        {
            res.push_back(mp[queries[i]]);
        }
        return res;
    }
};