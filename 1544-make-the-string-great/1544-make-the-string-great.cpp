class Solution {
public:
    string makeGood(string s) {
        int n = s.length();
        if(n ==0) return "";
        string res;
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<n;i++)
        {
            if(st.size()!=0 && abs(st.top() - s[i]) == 32) st.pop();
            else st.push(s[i]);
        }
        while(st.size())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin() , res.end());
        return res;
    }
};