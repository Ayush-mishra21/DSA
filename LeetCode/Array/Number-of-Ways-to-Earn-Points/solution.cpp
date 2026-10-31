class Solution {
    int mod = 1000000007;
    int dp[][];

    int solve(int target, int[][] types, int ind) {
        if (target == 0)
            return 1;
        if (ind >= types.length)
            return 0;
        if (dp[ind][target] != -1)
            return dp[ind][target];
        int sum = 0, ans = solve(target, types, ind + 1);
        for (int i = 1; i <= types[ind][0]; i++) {
            sum += types[ind][1];

            if (sum > target) {
                break;
            }

            ans = (ans + solve(target - sum, types, ind + 1)) % mod;
        }
        return dp[ind][target] = ans;
    }

    public int waysToReachTarget(int target, int[][] types) {
        dp = new int[types.length + 1][target + 1];
        for (int i = 0; i < dp.length; i++) {
            Arrays.fill(dp[i], -1);
        }
        return solve(target, types, 0);
    }
}