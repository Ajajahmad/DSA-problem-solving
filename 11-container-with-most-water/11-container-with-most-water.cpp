class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1, water = 0;
        while(i<j)
        {
            int h = min(height[i] , height[j]);
            water = max(water, (j-i)*h);
            while(h>=height[i] && i<j) i++;
            while(h>=height[j] && i<j) j--;
        }
        return water;
    }
};