#include <list>
class Solution {
public:
    string largestPalindromic(string num) {
        int n = num.length();
        if(n<2) return num;
        int zero=0 , flag =0;
        map<char,  int> mp;
        char mx = num[0];
        for(int i=0;i<n ;i++)
        {
                
                mp[num[i]]++;
        }
        for(auto it:mp)
        {
            if(it.second>1 && it.first!='0') flag = 1;
            if(it.first-'0' > mx-'0')
                mx = it.first;
        }
        
        if(flag ==0 )
        {
            num= "" ;
            num+=mx;
            return num;
        }
        std::list<char> lst;
        mx = '.';
        for(auto it:mp)
        {
            if(it.second==1)
            {
                if(it.first-'0' > mx-'0')
                    mx = it.first;
            }
            else if(it.second>1)
            {
                if(it.second%2==0)
                {
                    int value = it.second;
                    for(int i=0;i<value/2;i++)
                    {
                        lst.push_front(it.first);
                        lst.push_back(it.first);
                    }
                }
                else
                {
                    int value  = it.second-1;
                    for(int i=0;i<value/2;i++)
                    {
                        lst.push_front(it.first);
                        lst.push_back(it.first);
                    }
                    if(it.first-'0' > mx-'0')
                        mx = it.first;
                }
            }
        }
        int sz = lst.size();
        std::list<char>::iterator it;
        it = lst.begin();
        sz= sz/2+1;
        if(mx!='.')
        {
                     for(auto its:lst)
                        {
                            sz--;

                            if(sz==0)
                            {
                                lst.insert (it , mx);
                                break;
                            }
                            ++it;
                        }
        }
       
        string str;
        for (auto its = lst.begin(); its != lst.end(); ++its)
        {
           str+=*its;
        }
        return str;
    }
};