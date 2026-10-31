class Solution {
public:
    int solve(int n) {

        if(n == 0) return 0;

        int ans = INT_MAX;

        for(int i = 1; i * i <= n; i++) {

            ans = min(ans, 1 + solve(n - i*i));

        }

        return ans;
    }

    int numSquares(int n) {
        return solve(n);
    }
};