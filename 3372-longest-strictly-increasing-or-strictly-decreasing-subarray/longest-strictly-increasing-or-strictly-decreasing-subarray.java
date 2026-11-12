
class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int n = nums.length;

        int[] dp1 = new int[n];
        int[] dp2 = new int[n];

        Arrays.fill(dp1, 1);
        Arrays.fill(dp2, 1);

        int ans = 1;

        for (int i = 1; i < n; i++) {

            // Increasing contiguous subarray
            if (nums[i] > nums[i - 1]) {
                dp1[i] = dp1[i - 1] + 1;
            }

            // Decreasing contiguous subarray
            if (nums[i] < nums[i - 1]) {
                dp2[i] = dp2[i - 1] + 1;
            }

            ans = Math.max(ans, Math.max(dp1[i], dp2[i]));
        }

        return ans;
    }
}
