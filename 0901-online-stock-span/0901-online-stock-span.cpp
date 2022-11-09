class StockSpanner {
public:
    stack<pair<int,int>> st;
    int i ;
    StockSpanner() {
        i = 0;
    }
    
    int next(int price) {
        if(st.size()==0 || st.top().first > price)
        {
            st.push({price , i});
            i++;
           return 1;
        }
        
        while(st.size()>0 && price>= st.top().first)
        {
            st.pop();
        }
        int ind = (st.size()==0)? 0: st.top().second;
        if(st.size() !=0 ) ind++;
        int ans = i-ind+1;
        st.push({price, i});
        i++;
        return ans ;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */