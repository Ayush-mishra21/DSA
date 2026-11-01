class Solution {
    public int minMergedInteger(int[] nums) {
        int ans = Integer.MAX_VALUE;
        for(int i = 1;  i < nums.length; i++){
            if(i % 2 == 0)continue;
            String str = Integer.toString(nums[i - 1]) + Integer.toString(nums[i]);
            ans = Math.min(ans, Integer.parseInt(str));
        }
        return ans;
    }
}