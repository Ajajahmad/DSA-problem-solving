class Solution {
public:
    string frequencySort(string s) {
        map<char , int> mp;
        int n = s.length();
        for(int i=0;i<n;i++)
            mp[s[i]]++;
        priority_queue< pair<int,char>  > pq;
        for(auto it:mp)
        {
            pq.push({it.second , it.first});
        }
        
        s="";
        while(pq.size()!=0)
        {
            int f = pq.top().first;
            char ch = pq.top().second;
            while(f--)
                s+=ch;
            pq.pop();
        }
        return s;
    }
};