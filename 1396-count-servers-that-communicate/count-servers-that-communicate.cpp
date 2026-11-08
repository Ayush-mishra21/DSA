class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
    }

    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int total = m * n;

        parent.resize(total);
        sz.assign(total, 1);

        for (int i = 0; i < total; i++)
            parent[i] = i;

        // Union servers in the same row
        for (int i = 0; i < m; i++) {
            int first = -1;

            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int node = i * n + j;

                    if (first == -1)
                        first = node;
                    else
                        Union(first, node);
                }
            }
        }

        // Union servers in the same column
        for (int j = 0; j < n; j++) {
            int first = -1;

            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 1) {
                    int node = i * n + j;

                    if (first == -1)
                        first = node;
                    else
                        Union(first, node);
                }
            }
        }

        // Count servers whose component size > 1
        int ans = 0;
        unordered_set<int> st;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int node = i * n + j;
                    int ultimateParent = find(node);

                    if (sz[ultimateParent] > 1 &&
                        st.find(ultimateParent) == st.end()) {

                        ans += sz[ultimateParent];
                        st.insert(ultimateParent);
                    }
                }
            }
        }

        return ans;
    }
};