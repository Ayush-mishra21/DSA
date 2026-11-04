
class Solution {
public:
    multiset<int> low, high;
    long long lowSum = 0, highSum = 0;

    void balance() {
        while(low.size() > high.size() + 1) {
            int val = *low.rbegin();

            low.erase(prev(low.end()));
            lowSum -= val;

            high.insert(val);
            highSum += val;
        }

        while(low.size() < high.size()) {
            int val = *high.begin();

            high.erase(high.begin());
            highSum -= val;

            low.insert(val);
            lowSum += val;
        }
    }

    void insert(int val) {
        if(low.empty() || val <= *low.rbegin()) {
            low.insert(val);
            lowSum += val;
        }
        else {
            high.insert(val);
            highSum += val;
        }

        balance();
    }

    void remove(int val) {
        auto it = low.find(val);

        if(it != low.end()) {
            low.erase(it);
            lowSum -= val;
        }
        else {
            it = high.find(val);
            high.erase(it);
            highSum -= val;
        }

        balance();
    }

    long long getCost() {
        long long median = *low.rbegin();

        return median * low.size() - lowSum
             + highSum - median * high.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<long long> cost(n - x + 1);

        // First window
        for(int i = 0; i < x; i++) {
            insert(nums[i]);
        }

        cost[0] = getCost();

        // Sliding window
        for(int i = x; i < n; i++) {
            remove(nums[i - x]);
            insert(nums[i]);

            cost[i - x + 1] = getCost();
        }

        // DP
        const long long INF = LLONG_MAX / 2;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for(int t = 1; t <= k; t++) {
            curr[n] = INF;

            for(int i = n - 1; i >= 0; i--) {

                // Skip current index
                curr[i] = curr[i + 1];

                // Take subarray of size x
                if(i + x <= n) {
                    curr[i] = min(curr[i],
                                  cost[i] + prev[i + x]);
                }
            }

            prev = curr;
        }

        return prev[0];
    }
};
