class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        if(nums.size() < 4)return ans;
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && j < nums.size() && nums[j] == nums[j - 1])
                    continue;
                int k = j + 1, l = nums.size() - 1;
                while (k < l) {
                    long long sum = (long)nums[i] + (long)nums[j] + (long)nums[k] + (long)nums[l];
                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        while (k < nums.size() && nums[k] == nums[k - 1]) {
                            k++;
                        }
                        l--;
                        while (l >= 0 && nums[l] == nums[l + 1]) {
                            l--;
                        }
                    } else if (sum > target) {
                        l--;
                    } else {
                        k++;
                    }
                }
            }
        }
        return ans;
    }
};