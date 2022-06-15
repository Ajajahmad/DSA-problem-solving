class Solution {
public:
    bool check(string &s1, string &s2)
    {
        if(s1.size()!=s2.size()+1 ) return false;
        int first =0 ,second=0;
        while(first<s1.length())
        {
            if(s1[first] == s2[second])
            {
                first++;
                second++;
            }
            else
            {
                first++;
            }
        }
        if(first == s1.size() && second == s2.size()) return true;
        return false;
    }
    static bool comp(string &s1 , string &s2)
    {
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin() , words.end() ,comp);
        int n = words.size();
        vector<int> dp(n,1);
        int mx =1;
        for(int i=0;i<n;i++)
        {
            for(int pre = 0;pre<i;pre++)
            {
                if(check(words[i],words[pre])) 
                    dp[i] =max(dp[i] , dp[pre]+1);
            }
            mx = max(mx , dp[i]);
        }
        return mx;
            
    }
};