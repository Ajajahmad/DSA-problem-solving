class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char , int> mp;
        int n = s.length();
        for(char &a:s) mp[a]++;
        int unique = mp.size();
        
        
        int mx = 0;
        for(int i=1;i<=unique;i++)
        {
            mx = max(mx, fun(s, k ,i));
        }
        return mx;
    }
    
    
    int fun(string s , int k , int unique)
    {
        int n = s.length(), i=0, j=0;
        unordered_map<char , int> mp;
        
        int noOfChWithK = 0, res= 0;
        while(j<n)
        {
            mp[s[j]]++;
            if(mp[s[j]]==k) noOfChWithK++;
            while(mp.size() > unique)
            {
                if(mp[s[i]]==k) noOfChWithK--;
                mp[s[i]]--;
                
                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                i++;
            }
            if(mp.size()== noOfChWithK) res= max(res , j-i+1);
            j++;
        }
        return res;
    }
};