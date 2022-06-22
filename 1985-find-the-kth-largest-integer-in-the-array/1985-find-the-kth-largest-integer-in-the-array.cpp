class Solution {
public:
    struct comparator{
        bool operator()(string&s1 , string &s2){
            if(s1.length()>s2.length()) return true;
            else if(s1.length()<s2.length()) return false;
            else
            {
                for(int i=0;i<s1.length();i++)
                {
                    int a = s1[i]-'0';
                    int b = s2[i] - '0';
                    if(a>b) return true;
                    else if(a<b) return false;
                }
                return false;
            }
        }
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        priority_queue<string , vector<string> , comparator> pq;
        for(auto it:nums)
        {
            pq.push(it);
            if(pq.size()>k)
                pq.pop();
        }
        return pq.top();
    }
};