class Solution {
    String ans = "";
    void slove(int n, int k, String res){
        if(k == 0){
            ans = res;
            return;
        }
        if(!ans.equals("")){
            return;
        }
        for(int i = 1; i <= 9; i++){
            
        }
    }
    public String getPermutation(int n, int k) {
        solve(n, k, "");
    }
}