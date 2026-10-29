class Solution {
public:
    vector<vector<int>> dp;
    string longestPalindrome(string s) {
        string s1 = s;
        int start = -1, maxlen = 0;
        dp.resize(s.size(), vector<int>(s.size(), 0));
        reverse(s1.begin(), s1.end());
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = s1.size() - 1; j >= 0; j--) {
                if (s[i] == s1[j]) {
                    if (j + 1 < s1.size() && i + 1 < s.size())
                        dp[i][j] += dp[i + 1][j + 1] + 1;
                    else
                        dp[i][j] += 1;
                    int len = dp[i][j];
                    if (i + j + len == s.size()) {
                        if (len > maxlen) {
                            maxlen = len;
                            start = i; 
                        }
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        if (start == -1)
            return "";
        return s.substr(start, maxlen);
    }
};