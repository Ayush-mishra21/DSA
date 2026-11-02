class Solution {
public:
    long long valid(vector<int>& nums, vector<int>& cost, int mid) {
        long long res = 0;
        for (int i = 0; i < nums.size(); i++) {
            long long diff = abs((long)nums[i] - (long)mid) * (long)cost[i];
            res += diff;
        }
        return res;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int i = *min_element(nums.begin(), nums.end()),
            j = *max_element(nums.begin(), nums.end());
        long long ans = LLONG_MAX;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            long long a = valid(nums, cost, mid);
            long long b = valid(nums, cost, mid + 1);
            if (a > b) {
                ans = min(ans, b);
                i = mid + 1;
            } else {
                ans = min(ans, a);
                j = mid - 1;
            }
        }
        return ans;
    }
};