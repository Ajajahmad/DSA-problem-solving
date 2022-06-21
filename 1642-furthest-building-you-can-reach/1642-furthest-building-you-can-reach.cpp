class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int ans = 0;
        priority_queue<int> pq;
        for(int i=1;i<heights.size();i++) {
            if (heights[i] <= heights[i-1]) {
                ans++;
                continue;
            }
            int diff = heights[i] - heights[i-1];
            int lowestLadderHeight = !pq.empty() ? -1 * pq.top() : INT_MAX;
            if (ladders > 0) {
                ans++;
                ladders--;
                pq.push(-diff);
            }
            else if (bricks >= diff) {
                if (diff >= lowestLadderHeight) {
                    pq.pop();
                    pq.push(-diff);
                    bricks -= lowestLadderHeight;
                }
                else {
                    bricks -= diff;
                }
                ans++;
            }
            else if (bricks >= lowestLadderHeight) {
                pq.pop();
                bricks -= lowestLadderHeight;
                ans++;
            }
            else {
                break;
            }
        }
        
        return ans;
    }
};