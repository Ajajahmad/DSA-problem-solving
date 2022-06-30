class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue< pair<long long int,pair<int,int>> >pq;
        for(int i=0;i<points.size();i++)
        {
            int x=points[i][0], y=points[i][1];
            long long int value = x*x + y*y;
            pq.push({value, {x,y}});
            if(pq.size()>k)
                pq.pop();
        }
        vector<vector<int>> res;
        while(pq.size()!=0)
        {
            int x= pq.top().second.first;
            int y= pq.top().second.second;
            vector<int>ans;
            ans.push_back(x);
            ans.push_back(y);
            res.push_back(ans);
            pq.pop();
        }
        return res;
    }
};