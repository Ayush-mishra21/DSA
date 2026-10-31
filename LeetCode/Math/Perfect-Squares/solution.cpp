class Solution {
public:
    vector<int>dp;
    int solve(int n) {

        if(n == 0) return 0;

        int ans = INT_MAX;
        if(dp[n] != -1)return dp[n];
        for(int i = 1; i * i <= n; i++) {

            ans = min(ans, 1 + solve(n - i*i));

        }

        return dp[n] = ans;
    }

    int numSquares(int n) {
        dp.resize(n + 1, -1);
        return solve(n);
    }
};