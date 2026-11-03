class Solution {
    public int minMoves(int[] nums) {
        int max_ = Arrays.stream(nums).max().getAsInt();
        int ans = 0;
        for(int A : nums){
            ans += Math.abs(A - max_);
        }
        return ans;
    }
}