class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp, mp1;
        for(int i=0;i<arr.size() ;i++) mp[arr[i]]++;
        for(auto a:mp)
        {
            mp1[a.second]++;
        }
        for(auto a:mp1)
        {
            if(a.second>1) return false;
        }
        return true;
    }
};