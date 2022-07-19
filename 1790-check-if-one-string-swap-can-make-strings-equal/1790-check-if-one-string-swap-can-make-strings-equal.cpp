class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        string str1=s1,str2=s2;
        sort(str1.begin(),str1.end());
        sort(str2.begin(),str2.end());
        if(str1!=str2) return false;
        int dif = 0;
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]!=s2[i]) dif++;
        }
        if(dif>2) return false;
        return true;
    }
};