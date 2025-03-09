
The basic idea is to maintain a hash table for each element num in nums, using num as key and its index (0-based) as value. For each num, search for target - num in the hash table. If it is found and is not the same element as num, then we are done.

The code is as follows. Note that each time before we add num to mp, we search for target - num first and so we will not hit the same element.
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int,vector<int>>mp;
            for(int i=0; i<nums.size(); i++){
                if(mp.find(nums[i])!=mp.end()){
                    mp[nums[i]].push_back(i);
                    return mp[nums[i]];
                }
                else{
                    mp[target-nums[i]].push_back(i);
                }
            }
            return {};
        }
    };