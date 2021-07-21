class Solution {
    public int maxProfit(int k, int[] prices) {
        if (prices == null || prices.length < 2 || k == 0) {
            return 0;
        }

        int [][] dp = new int[prices.length ][2 * k + 1];
        for (int j = 1; j < 2 * k; j += 2) {
            dp[0][j] = -prices[0];
        }

        for (int i = 1; i < prices.length; i++) {
            for (int j = 0; j < 2 * k - 1; j += 2) {
                dp[i][j + 1] = Math.max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
                dp[i][j + 2] = Math.max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
            }
        }
        return dp[prices.length - 1][2 * k];
    }



    public static void test(int k, int[] prices, int expected)
    {
        Solution sol = new Solution();
        int result = sol.maxProfit(k, prices);
        if(result != expected )
        {
            System.out.println("FAILED");
            return;
        }
        System.out.println("PASSED");
    }

    public static  void main(String[] args) {
        test(2, new int[]{2,4,1}, 2);
        test(2, new int[]{3,2,6,5,0,3}, 7);
    }
}