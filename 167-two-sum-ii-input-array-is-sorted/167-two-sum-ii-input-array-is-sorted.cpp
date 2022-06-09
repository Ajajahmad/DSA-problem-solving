class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int,int> mp;
        for(int i=0;i<numbers.size();i++) mp[numbers[i]] = i+1;
        vector<int> res;
        for(int i=0;i<numbers.size();i++)
        {
            if(mp.find(target-numbers[i])!=mp.end()) {
                res.push_back(i+1);
                res.push_back(mp[target-numbers[i]]);
                break;
            }
        }
        return res;
    }
};