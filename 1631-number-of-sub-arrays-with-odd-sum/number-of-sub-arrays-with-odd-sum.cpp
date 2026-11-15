class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int even = 1, odd = 0, ans = 0;
        int mod = 1000000007, sum = 0;

        for (int A : arr) {
            sum += A;

            if (sum % 2 == 0) {
                ans = (ans + odd) % mod;
                even++;
            } 
            else {
                ans = (ans + even) % mod;
                odd++;
            }
        }

        return ans;
    }
};