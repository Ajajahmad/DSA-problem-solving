class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp1,mp2;
        vector<vector<int>> res;
        for(int i=0;i<nums1.size();i++) mp1[nums1[i]]=1;
        for(int i=0;i<nums2.size();i++)
        {
            if(mp1.find(nums2[i])!=mp1.end()) mp1[nums2[i]]++;
        }
        for(int i=0;i<nums2.size();i++) mp2[nums2[i]]=1;
        for(int i=0;i<nums1.size();i++)
        {
            if(mp2.find(nums1[i])!=mp2.end()) mp2[nums1[i]]++;
        }
        vector<int> ans,ans2;
        for(auto it:mp1)
        {
            if(it.second==1) ans.push_back(it.first);
        }
        res.push_back(ans);
        ans.clear();
        for(auto it:mp2)
        {
            if(it.second==1) ans2.push_back(it.first);
        }
        res.push_back(ans2);
        return res;
    }
};