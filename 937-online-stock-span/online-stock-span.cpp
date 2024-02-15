class StockSpanner {
public:
    StockSpanner() {
        
    }
    
      int next(int price) {
            int span = 1;
        while (!priceStack.empty() && price >= priceStack.top().first) {
            span += priceStack.top().second;
            priceStack.pop();
        }
        priceStack.push({price, span});
        return span;
    }

private:
    std::stack<std::pair<int, int>> priceStack; // {price, span}
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */