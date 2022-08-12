class Solution {
public:
    int evalRPN(vector<string>& a) {
        int n = a.size();
        stack<int> st;
        int res = 0;
        for(int i=0;i<n;i++)
        {
            if(a[i]!="+" && a[i]!="-" && a[i]!="*" && a[i]!="/")
            {
                
                st.push(stoi(a[i]));
            }
            else if(a[i]=="+" || a[i]=="-" || a[i]=="*" || a[i]=="/")
            {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                if(a[i]=="+")
                {
                    st.push(x+y);
                }
                else if(a[i]=="-")
                    st.push(y-x);
                else if(a[i]=="*")
                    st.push(y*x);
                else 
                    st.push(y/x);
            }
        }
        return st.top();
    }
};