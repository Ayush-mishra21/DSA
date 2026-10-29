class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        unordered_map<char, int> mp;
        int i = 0, j = 0;
        int ans = INT_MIN;
        //unordered_map<char, int> mp;
        // int i = 0, j = 0;
        while (j < s.size()) {
            mp[s[j]]++;
            if (mp[s[j]] >1) {
                while (mp[s[j]] > 1) {
                    mp[s[i]]--;
                    i++;
                }
                j++;
            } else {
                ans = max(ans, j - i + 1);
                j++;
            }
        }

        return ans;
    }
};