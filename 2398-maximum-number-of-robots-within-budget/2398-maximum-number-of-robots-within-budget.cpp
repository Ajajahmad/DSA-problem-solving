class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int i=0,j=0;
        int  n = chargeTimes.size();
        int res =0;
        long long sum =0;
        deque<int> dq;
        int mx = 0;
        while(j<n)
        {
            sum += runningCosts[j];
            while(!dq.empty() && chargeTimes[j] >= chargeTimes[dq.back()]) dq.pop_back();
            dq.push_back(j);
            mx = chargeTimes[dq.front()];
            long long cost = mx + (j-i+1)*sum;
            if(cost<=budget)
            {
                res = max(res , j-i+1);
            }
            else
            {
                while(cost>budget)
                {
                    
                
                    if(!dq.empty() && dq.front()<=i)
                        dq.pop_front();
                    sum -= runningCosts[i];
                    i++;
                    mx = dq.empty()? 0 : chargeTimes[dq.front()];
                    cost = mx + (j-i+1)*sum;
                }
                res = max(res , j-i+1);
            }
            j++;
        }
        return res;
    }
};