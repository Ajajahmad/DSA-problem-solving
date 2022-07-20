class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char,vector<int>> mp;
        for(int i=0;i<s.length();i++)
            mp[s[i]].push_back(i);
        map<string , int> mpW;
        for(int i=0;i<words.size(); i++)
        {
            mpW[words[i]]++;
        }
        int res=0,pre = -1;
        for(auto it:mpW)
        {
            string str = it.first;;
            int j;
            pre = -1;
            for(j=0;j<str.length();j++)
            {
                if(mp.find(str[j])==mp.end()) break;
                vector<int> temp = mp[str[j]] ;
                int count = 0;
                for(int k=0;k<temp.size();k++)
                {
                    if(temp[k]>pre)
                    {
                        pre = temp[k];
                        count++;
                        break;
                    }
                }
                if(count==0 ) break;
            }
            if(j==str.length()) res+=it.second;
        }
        return res;
        
    }
};