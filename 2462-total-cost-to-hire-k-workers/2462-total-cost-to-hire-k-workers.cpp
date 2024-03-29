class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        long long sum = 0;
        int n = costs.size();
        int j  =  n-1;
        
        priority_queue<pair<int,int > , vector<pair<int,int >> , greater<pair<int,int >> > pq;
        int i = 0;
        int count = c;
        while(i< n && count--)
        {
            pq.push({costs[i] , 0});
            i++;
        }
        count = c;
        
        while(j>i && count--)
        {
            pq.push({costs[j] ,1});
            j--;
        }
        while(i<=j && k)
        {
            pair<int , int > val = pq.top();
            pq.pop();
            sum+=val.first;
            if(val.second == 0)
            {
                pq.push({costs[i] ,0});
                i++;
            }
            else 
            {
                pq.push({costs[j] , 1});
                j--;
            }
            k--;
        }
        while(k--)
        {
            pair<int ,int> val = pq.top();
            pq.pop();
            sum += val.first;
        }
        return sum;
    }
};