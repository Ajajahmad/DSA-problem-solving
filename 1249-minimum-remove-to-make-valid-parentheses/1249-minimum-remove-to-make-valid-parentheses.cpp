class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack< pair<char, int> > st;
        stack<int> st1;
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') st.push({s[i], i});
            else if( s[i]==')')
            {
                if(st.size()!=0 && st.top().first=='(') st.pop();
                else
                    st.push({s[i] , i});
            }
        }
        
        
        string res="" ;
        while(st.size()!=0)
        {
            st1.push(st.top().second);
            st.pop();
        }
        
        
        for(int i=0;i<n;i++)
        {
            if(st1.size()!=0 && st1.top()==i){
                st1.pop();
                continue;
            }
            else
                res+=s[i];
        }
        return res;
    }
};