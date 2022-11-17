class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int s1= (abs(ax1-ax2)*abs(ay1-ay2));
        int s2= (abs(bx1-bx2)*abs(by1-by2));
        if(ay2<=by1 || ay1>=by2 || ax1>=bx2 || ax2<=bx1) return s1+s2;
        
        
        int x1=0,x2=0,y1=0,y2=0;
        x1= max(ax1,bx1);
        x2 = min(bx2,ax2);
        y1= max(ay1,by1);
        y2 = min(ay2,by2);
        return s1+s2 - (abs(x1-x2) * abs(y1-y2));
    }
};