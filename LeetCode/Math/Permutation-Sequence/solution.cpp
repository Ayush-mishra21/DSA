class Solution {
    String ans = "";
    void slove(int n, int k, String res, int ind){
        if(k == 0){
            ans = res;
            return;
        }
        if(!ans.equals("")){
            return;
        }
        for(int i = 1; i <= n; i++){
            String newres = res + (i - '0');
            solve(n, k - 1, newres, ind + 1);
        }
    }
    public String getPermutation(int n, int k) {
        solve(n, k, "");
    }
}