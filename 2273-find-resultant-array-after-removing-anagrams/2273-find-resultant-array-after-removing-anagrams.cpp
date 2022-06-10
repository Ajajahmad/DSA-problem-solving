class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size();
        vector<string> res;
        if(n==0 && n==1) return words;
        vector<string>str = words;
        for(int i=0;i<n;i++)
        {
            sort(str[i].begin(),str[i].end());
        }
        res.push_back(words[0]);
        for(int i=1;i<n;i++)
        {
            if(str[i]==str[i-1]) continue;
            else res.push_back(words[i]);
        }
        return res;
    }
};