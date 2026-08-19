class Solution {
   public int maxProfit(int[] prices) {
        int mx = 0, num = 0;
        for(int i = prices.length - 1;i >= 0; i--){
            mx = Math.max(mx, num - prices[i]);
            if(num< prices[i])
                num = prices[i];
        }
        return mx;
    }
}