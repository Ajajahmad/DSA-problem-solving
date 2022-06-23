class Solution {
public:
    static bool sortcol(const vector<int>& v1, const vector<int>& v2)
    {
        if(v1[1] == v2[1])
            return (v1[0]<v2[0]);
        else
            return v1[1]<v2[1];
    }
    
    int scheduleCourse(vector<vector<int>>& c) {
        int n = c.size();
        priority_queue< int > pq;
        
        sort(c.begin() , c.end(), sortcol);
        
        int time=0;
        for(int i=0;i<n;i++)
        {
            if(c[i][0]<=c[i][1]){
                if(c[i][0] +time <= c[i][1]){
                    pq.push(c[i][0]);
                    time += c[i][0];
                }
                else
                {
                    if(pq.top()> c[i][0])
                    {
                        time -= pq.top();
                        pq.pop();
                        pq.push(c[i][0]);
                        
                        time += c[i][0];
                    }
                }
            }
        }
        return pq.size();
    }
};