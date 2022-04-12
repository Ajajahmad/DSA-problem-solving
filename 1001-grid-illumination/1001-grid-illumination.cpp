class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        map<int,int>x,y,ad,dd;
        vector<int>res;
        if(n==0) return res;
        set<pair<int,int>> s;
        for(int i=0;i<lamps.size();i++)
        {
            int a=lamps[i][0];
            int b = lamps[i][1];
            if(s.find({a,b})!=s.end()) continue;
            x[a]++;
            y[b]++;
            ad[a+b]++;
            dd[a-b]++;
            s.insert({a,b});
        }
        
        for(int i=0;i<queries.size();i++)
        {
            int a = queries[i][0];
            int b = queries[i][1];
            if(x[a] || y[b] || ad[a+b] || dd[a-b])
            {
                res.push_back(1);
                for(int j=a-1;j<=a+1;j++)
                {
                    for(int k=b-1;k<=b+1;k++)
                    {
                        if(j>=0 && j<n&& k>=0 && k<n &&s.find({j,k})!=s.end())
                        {
                            s.erase({j,k});
                            x[j]--;
                            y[k]--;
                            ad[j+k]--;
                            dd[j-k]--;
                        }
                    }
                }
            }
            else
                res.push_back(0);
            
        }
        
        return res;
    }
};