class Solution {
    String ans = "";
    int K;
    boolean[] visited = new boolean[10];

    void solve(int n, String res) {

        if (res.length() == n) {
            K--;

            if (K == 0) {
                ans = res;
            }
            return;
        }

        for (int i = 1; i <= n; i++) {

            if (visited[i]) continue;

            visited[i] = true;

            solve(n, res + i);

            visited[i] = false;

            if (!ans.isEmpty()) return;
        }
    }

    public String getPermutation(int n, int k) {
        K = k;
        solve(n, "");
        return ans;
    }
}