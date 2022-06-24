class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long int> pq;
        long long int n = target.size();
        unsigned int sum=0;
        for(int i=0;i<n;i++){
            sum+=target[i];
            pq.push((long long )target[i]);
        }
        
        while(pq.top()!=1){
             long long int max = pq.top();
            pq.pop();
            sum = sum - max;
            if(sum<=0 || sum>=max) return false;
            
            max = max % sum;
            
             sum += max;
            pq.push(max>0 ? max : sum);
        }
        return true;
    }
};