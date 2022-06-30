class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> mp;
        int n = s.length();
        for(int i=0;i<n;i++)
        {
                mp[s[i]] = i;
        }
        vector<int> res;
        int st=0,l=0;
        while(st<n)
        {
            int i = st;
            l = mp[s[i]];
            i++;
            while(i<=l)
            {
                if(mp[s[i]]>l)
                    l=mp[s[i]];
                i++;
            }
            res.push_back(l-st+1);
            st=l+1;
        }
        return res;
    }
};