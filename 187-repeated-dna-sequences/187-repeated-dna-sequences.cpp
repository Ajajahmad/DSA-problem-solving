class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string , int>mp;
        int n = s.length();
        string str="",temp="";
        int i=0,j=0;
        while(j<n)
        {
            str += s[j];
            if(j-i+1 <10) j++;
            else
            {
                mp[str]++;
                temp = str.substr(1,9);
                str = temp;
                i++;
                j++;
            }
        }
        vector<string> res;
        for(auto it:mp)
        {
            if(it.second>1)
            {
                res.push_back(it.first);
            }
            
        }
        return res;
    }
};