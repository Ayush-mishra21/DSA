class Solution {
public:
    vector<long long> dp;

    long long solve(int n, vector<int>& costs, int ind) {
        if (ind == n)
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        long long ans = LLONG_MAX;

        if (ind + 1 <= n) {
            long long temp = solve(n, costs, ind + 1)
                           + costs[ind] + 1LL;
            ans = min(ans, temp);
        }

        if (ind + 2 <= n) {
            long long temp = solve(n, costs, ind + 2)
                           + costs[ind + 1] + 4LL;
            ans = min(ans, temp);
        }

        if (ind + 3 <= n) {
            long long temp = solve(n, costs, ind + 3)
                           + costs[ind + 2] + 9LL;
            ans = min(ans, temp);
        }

        return dp[ind] = ans;
    }

    int climbStairs(int n, vector<int>& costs) {
        dp.resize(n + 1, -1);
        return solve(n, costs, 0);
    }
};