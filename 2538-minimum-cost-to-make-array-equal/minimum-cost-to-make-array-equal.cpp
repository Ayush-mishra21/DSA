
class Solution {
public:
    long long valid(vector<int>& nums, vector<int>& cost, int mid) {
        long long res = 0;

        for(int i = 0; i < nums.size(); i++) {
            long long diff = abs((long long)nums[i] - mid);
            res += diff * cost[i];
        }

        return res;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int i = *min_element(nums.begin(), nums.end());
        int j = *max_element(nums.begin(), nums.end());

        while(i < j) {
            int mid = i + (j - i) / 2;

            long long a = valid(nums, cost, mid);
            long long b = valid(nums, cost, mid + 1);

            if(a > b) {
                i = mid + 1;
            }
            else {
                j = mid;
            }
        }

        return valid(nums, cost, i);
    }
};
