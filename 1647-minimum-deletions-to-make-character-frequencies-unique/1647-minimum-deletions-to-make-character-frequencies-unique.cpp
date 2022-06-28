class Solution {
public:
    int minDeletions(string s) {
        int n = s.length();
        map<int, vector<char> > mp;
        int res=0;
        sort(s.begin() , s.end());
        int count =0;
        for(int i=0;i<n;i++)
        {
            if(i+1!=n && s[i]==s[i+1]){
                count++;
                continue;
            }
            count++;
            mp[count].push_back(s[i]);
            count=0;
        }
        
        for(auto it:mp)
        {
            if(it.second.size()>1)
            {
                int value = it.second.size();
                while(value>1)
                {
                    int cnt = it.first;
                    vector<char> temp = it.second;
                    int f = cnt;
                    while(f!=0 && mp.find(f)!=mp.end())
                    {
                        f--;
                    }
                    int sz = temp.size();
                    char ch = temp[sz-1];
                    temp.pop_back();
                    res += cnt - f;
                    mp[f].push_back(ch);
                    value--;
                }
            }
        }
        return res;
        
        
    }
};