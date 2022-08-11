class Solution {
public:
    bool canConstruct(string r, string m) {
        vector<int> temp(26,0);
        for(int i=0;i<r.size();i++)
        {
            temp[r[i]-'a']++;
        }
        int count = r.size();
        for(int i = 0;i<m.size();i++)
        {
            if(temp[m[i]-'a'] >0 )
            {
                temp[m[i]-'a']--;
                count--;
            }
            if(count==0) return true;
                
            
        }
        return false;
    }
};