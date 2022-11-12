class MedianFinder {
public:
    priority_queue<int> pq1;
    priority_queue<int, vector<int> , greater<int>> pq2;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq1.size() ==0) pq1.push(num);
        else{
            if(num < pq1.top())
            {
                pq1.push(num);
                int sz1 = pq1.size() , sz2 = pq2.size();
                if(sz1> sz2)
                {
                   
                        int tp = pq1.top();
                        pq1.pop();
                        pq2.push(tp);
                    
                }
            }
            else
            {
                pq2.push(num);
                int sz1 = pq1.size() , sz2=pq2.size();
                if(abs(sz1-sz2) >1)
                {
                    int tp = pq2.top();
                    pq2.pop();
                    pq1.push(tp);
                }
            }
        }
    }
    
    double findMedian() {
        if(pq1.size() == 0 ) return 0;
        else if(pq2.size()==0) return pq1.top();
        double  ans , div = 2;
        // cout<<pq1.top()<<" "<<pq2.top()<<endl;
        if(pq1.size() == pq2.size()) ans = (pq1.top() + pq2.top()) / div;
        
        else ans = pq2.top();
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */