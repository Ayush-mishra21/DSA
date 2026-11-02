class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans = 0, mid = (nums.size() - 1) / 2;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            ans += abs(nums[mid] - nums[i]);
        }
        return ans;
    }
};