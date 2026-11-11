class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        long long ans = 0;
        long long min_cost = min(cost1 + cost2, costBoth);
        int min_need = min(need1, need2);
        ans += (min_need * min_cost);
        need1 -= min_need;
        need2 -= min_need;
        if (need1 > 0) {
            min_cost = min(cost1, costBoth);
            ans += (need1 * min_cost);
        }
        if (need2 > 0) {
            min_cost = min(cost2, costBoth);
            ans += (need2 * min_cost);
        }
        return ans;
    }
};