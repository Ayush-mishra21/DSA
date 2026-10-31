class Solution {
    int mod = 1000000007;

    int solve(int target, int[][] types, int ind) {
        if (target == 0)
            return 1;
        if (ind >= types.length)
            return 0;
        int sum = 0, ans = solve(target, types, ind + 1);
        for (int i = 1; i <= types[ind][0]; i++) {
            if (target - sum < 0) {
                break;
            }
            sum += types[ind][1];
            ans = (ans + (solve(target - sum, types, ind + 1)) % mod);
        }
        return ans;
    }

    public int waysToReachTarget(int target, int[][] types) {
        return solve(target, types, 0);
    }
}