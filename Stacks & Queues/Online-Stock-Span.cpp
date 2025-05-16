class StockSpanner {
    stack<pair<int, int>> st; // pair of (price, span)

public:
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;
        // While stack top price <= current price, pop and accumulate span
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};
