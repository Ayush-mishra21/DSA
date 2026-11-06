class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {

        int m = logs.size();
        int q = queries.size();

        vector<int> ans(q, 0);

        sort(logs.begin(), logs.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        vector<pair<int, int>> v;

        for (int i = 0; i < q; i++) {
            v.push_back({queries[i], i});
        }

        sort(v.begin(), v.end());

        unordered_map<int, int> mp;
        int cnt = 0;

        int l = 0, r = 0;

        for (auto [time, idx] : v) {

            int a = time - x;
            int b = time;

            while (r < m && logs[r][1] <= b) {
                mp[logs[r][0]]++;
                r++;
            }

            while (l < r && logs[l][1] < a) {
                mp[logs[l][0]]--;

                if (mp[logs[l][0]] == 0) {
                    mp.erase(logs[l][0]);
                }

                l++;
            }

            ans[idx] = n - mp.size();
        }

        return ans;
    }
};