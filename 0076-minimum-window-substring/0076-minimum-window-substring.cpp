class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> m(52,0) , mp(52,0);
          int st= 0 ,len=0;
        int sz = 0;
        for(int i=0;i<t.size();i++)
        {
            char ch = t[i];
            int idx;
            if(islower(ch)) idx = 26+(ch-'a');
            else idx = ch-'A';
            m[idx]++;
            cout<<idx<<" ";
        }                       // storing the ch frequecy of desires string t
        for(int i=0; i<52; i++) if(m[i]>0) sz++;
        int noOfCh = 0;
        int i = 0 , j=0, n = s.length() ,mn=n+1;
        
        while(j<n)
        {
            char ch = s[j];
            int idx;
            if(islower(ch)) idx = 26+(ch-'a');
            else idx = ch-'A';
            mp[idx]++;
            if( m[idx]>0 && (mp[idx]==m[idx]) ) noOfCh++;
          
            if(i<n &&i <=j && sz == noOfCh)
            {
                while(i<n &&i <= j && sz == noOfCh)
                {
                    if(mn > j-i+1)
                    {
                        st = i;
                        len = j-i+1;
                        mn = min(j-i+1, mn);
                    }
                    char chr = s[i];
                    int id ;
                    if(islower(chr)) id = 26+(chr-'a');
                    else id=chr-'A';
                    
                    if(m[id]>0 &&  mp[id]==m[id]) noOfCh--;
                    mp[id]--;
                    
                    i++;
                }
            }
            j++;
            
        }
       if(mn == n+1) return "";
        return s.substr(st,len);
        
        
        
    }
};