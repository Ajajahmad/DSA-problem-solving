class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int n=s.length();
        if(n==0) return 0;
        if(n==1) return 1;
        unordered_map<char , int> mp;
        int len=1;
        mp[s[0]]=0;
        int mx=1;
        for(int i=1;i<n;i++)
        {
            if(mp.find(s[i])==mp.end())
            {
                len++;
                mx= max(len, mx);
                mp[s[i]]=i;
            }
            else
            {
                mx = max(len,mx);
                int index = mp[s[i]];
                len = i -index-1;
                
                mp.clear();
                for(int j=index+1;j<=i;j++)
                    mp[s[j]] = j;
                len++;
                mx = max(len,mx);
            }
        }
        return mx;
    }
};