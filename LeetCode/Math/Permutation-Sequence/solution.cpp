class Solution {
    String ans = "";
    void solve(int n, int k, String res, int ind){
        if(res.length() == n && k == 0){
            ans = res;
            return;
        }
        if(!ans.equals("")){
            return;
        }
        for(int i = ind; i <= 9; i++){
            String newres = new String(res + (i + '0'));
            solve(n, k - 1, newres, i + 1);
        }
    }
    public String getPermutation(int n, int k) {
        solve(n, k, "", 1);
        return ans;
    }
}