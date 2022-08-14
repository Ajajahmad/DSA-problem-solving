class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> key(26,0),temp , res;
        if(p.size()>s.size()) return res;
        for(int i=0;i<p.length();i++)
            key[p[i]-'a']++;
        int sz = p.size();
        for(int i=0;i<=s.length()-sz ;i++)
        {
            temp = key;
            for(int j=i;j<i+sz;j++)
            {
                temp[s[j]-'a']--;
            }
            int count= 0;
            for(int j=0;j<26;j++)
            {
                if(temp[j]!=0) count++;
            }
            if(count==0) 
                res.push_back(i);
        }
        return res;
    }
};