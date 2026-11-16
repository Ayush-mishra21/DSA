class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            int sum = 0, i = 0, j = 0;
            string ans = "";
            for (j = 0; j < s.size(); j++) {
                sum += (s[j] - '0');
                if (j - i + 1 == k) {
                    ans += to_string(sum);
                    sum = 0;
                    i = j + 1;
                }
            }
            if (i < s.size())
                ans += to_string(sum);
            s = ans;
        }
        return s;
    }
};