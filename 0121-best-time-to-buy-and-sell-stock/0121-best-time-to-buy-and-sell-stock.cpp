class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int n = prices.size();
        if(n<2) return 0;
        int p1 = 0;
        int p2 = 1;
        while(p2<n){
            if(prices[p2] < prices[p1]){
                p1 = p2;
                p2++;
            }else{
                res = max(res, prices[p2] - prices[p1]);
                p2++;
            }
        }
        return res;
    }
};