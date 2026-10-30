class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        for(i = nums.size() - 1; i > 0; i--){
            if(nums[i - 1] < nums[i]){
                break;
            }
        }
        if(i == 0){
            reverse(nums.begin(), nums.end());
        }
        else{
            int j = i, res = i;
            while(j < nums.size()){
                if(nums[res] > nums[j] && nums[i - 1] < nums[j]){
                    res = j;
                }
                j++;
            }
            swap(nums[res], nums[i - 1]);
            sort(nums.begin() + i, nums.end());
        }
    }
};