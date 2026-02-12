class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
    }
    
    int next(int price) {
        // int c=1;
        // stack<int> temp=st;
        // while(!temp.empty() && temp.top()<=price){
        //     c++;
        //     temp.pop();
        // }
        // st.push(price);
        // return c;
        int c = 1;
        if(st.empty()){
            st.push({price,1});
            return 1;
        }    
        while(!st.empty() && st.top().first <= price){
            c+=st.top().second;
            st.pop();
        }
        st.push({price,c});
        return c;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */