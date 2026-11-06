
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> st;

        for(int i = 0; i < nums.size(); i++) {

            // Find the smallest element >= nums[i] - valueDiff
            auto it = st.lower_bound((long long)nums[i] - valueDiff);

            // Check whether a valid element exists
            if(it != st.end() && *it <= (long long)nums[i] + valueDiff) {
                return true;
            }

            // Insert current element
            st.insert(nums[i]);

            // Maintain window size <= indexDiff
            if(i >= indexDiff) {
                st.erase(nums[i - indexDiff]);
            }
        }

        return false;
    }
};
