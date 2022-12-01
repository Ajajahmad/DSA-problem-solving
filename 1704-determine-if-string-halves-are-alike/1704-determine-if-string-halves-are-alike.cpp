class Solution {
public:
    bool halvesAreAlike(string s) {
        vector<int> temp(300,0) ,temp1(300,0);
        for(int i=0;i<s.length()/2;i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
                temp[s[i]]++;
        }
         for(int i=s.length()/2;i<s.length();i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
                temp1[s[i]]++;
        }
        int a = 0, b=0;
        for(int i=0;i<300;i++){
            if(temp[i]!=0) a+=temp[i];
            if(temp1[i]!=0) b+=temp1[i];
        }
        // cout<<a<<" "<<b<<endl;
        return (a==b);
    }
};