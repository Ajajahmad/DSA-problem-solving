class Solution {
public:
    bool comp(string s1,string s2)
    {
        vector<int> a(300,0);
        for(int i=0;i<s1.length();i++)
        {
            a[s1[i]-'0'] = a[s1[i]-'0']+1;
        }
        for(int i=0;i<s2.length();i++)
        {
            a[s2[i]-'0'] = a[s2[i]-'0']-1;
        }
        for(int i=0;i<300;i++)
        {
            if(a[i]!=0) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        int i =0 , j=0;
        string str ="";
        while(j<m)
        {
            str+=s2[j];
            if(j-i+1<n) j++;
            else{
                string str1 = str.substr(i,n);
                if(comp(str1 , s1)) return true;
                i++;
                j++;
            }
        }
        return false;
    }
};