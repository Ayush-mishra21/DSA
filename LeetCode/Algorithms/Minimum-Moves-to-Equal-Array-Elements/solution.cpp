class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minElement = *min_element(nums.begin(), nums.end());
        int ans = 0;
        for(int A : nums){
            int diff = A - minElement;
            ans += diff;
        }
        return ans;
    }
};