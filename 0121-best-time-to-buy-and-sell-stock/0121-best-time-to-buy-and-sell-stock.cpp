class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int j = 0;
        int n = prices.size();
        for(int i=1;i<n;i++){
            if(prices[i]<prices[j]){
                j=i;
                continue;
            }else{
                maxi = max(maxi, prices[i]-prices[j]);
            }
        }
        return maxi;
    }
};