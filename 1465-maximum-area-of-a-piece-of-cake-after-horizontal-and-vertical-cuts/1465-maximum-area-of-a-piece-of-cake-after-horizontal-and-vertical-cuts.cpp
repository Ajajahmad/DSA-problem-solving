class Solution {
public:
    int maxArea(int h, int w, vector<int>& hor, vector<int>& ver) {
        hor.push_back(0);
        hor.push_back(h);
        ver.push_back(0);
        ver.push_back(w);
        sort(hor.begin(), hor.end());
        sort(ver.begin() , ver.end());
       long long int mx1=0, mx2=0;
        vector<int> hr,vr;
        int mod = 1e9+7;
        for(int i=0;i<hor.size()-1;i++)
        {
            hr.push_back(hor[i+1]-hor[i]);
            if(mx1<hr[i])
                mx1 = hr[i];
            mx1 = mx1%mod;
        }
        for(int i=0;i<ver.size()-1;i++)
        {
            vr.push_back(ver[i+1]- ver[i]);
             
             if(mx2<vr[i])
                mx2 =vr[i];
            mx2 = mx2%mod;
        }
        
        return (int)(mx1%mod * mx2%mod)%mod;
        
        
    }
};