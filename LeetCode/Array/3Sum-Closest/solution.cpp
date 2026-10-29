class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX, ans = -1;
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) == 0) {
                    return sum;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
                if (abs(sum - target) < diff) {
                    ans = sum;
                    diff = abs(sum - target);
                }
            }
        }
        return ans;
    }
};