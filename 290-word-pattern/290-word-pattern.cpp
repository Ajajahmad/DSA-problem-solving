class Solution {
public:
    bool wordPattern(string pat, string s) {
        map<char,string> mp;
        map<string,char> mp2;
        s+=" ";
        int i =0;
        int k=0;
        while(k<s.length())
        {
            string str ="";
            while(s[k]!=' ')
                str+=s[k++];
            if(mp.find(pat[i])==mp.end())
            {
                mp[pat[i]] = str;
            }
            else
            {
                if(mp[pat[i]] != str) return false;
            }
            if(mp2.find(str)==mp2.end())
                mp2[str] = pat[i];
            else
            {
                if(mp2[str]!= pat[i]) return false;
            }
            i++;
            k++;
        }
        if(i<pat.length()) return false;
        return true;
    }
};