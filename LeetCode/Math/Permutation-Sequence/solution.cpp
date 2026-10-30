class Solution {
    String ans = "";
    int K;
    void solve(int n, String res, int ind) {
        if (res.length() == n) {
            K -= 1;
            if (K == 0)
                ans = res;
            return;
        }
        for (int i = 1; i <= 9; i++) {
            String newres = new String(res + (i + '0'));
            if (res.length() > n)
                continue;
            solve(n, newres, i);
        }
    }

    public String getPermutation(int n, int k) {
        K = k;
        solve(n, k, "", 1);
        return ans;
    }
}