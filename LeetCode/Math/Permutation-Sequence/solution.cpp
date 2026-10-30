class Solution {
    String ans = "";
    void solve(int n, int k, String res, int ind){
        if(res.lengthk == 0){
            ans = res;
            return;
        }
        if(!ans.equals("") || ind > n){
            return;
        }
        for(int i = ind; i <= n; i++){
            String newres = new String(res + (i + '0'));
            solve(n, k - 1, newres, ind + 1);
        }
    }
    public String getPermutation(int n, int k) {
        solve(n, k, "", 1);
        return ans;
    }
}