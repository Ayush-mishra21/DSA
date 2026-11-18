class Solution {
public:
    bool valid(vector<vector<int>> qn, int x, int y, int n) {
        for (int i = 0; i < n; i++) {
            if (qn[x][i] == 1)
                return false;
        }
        for (int i = 0; i < n; i++) {
            if (qn[i][y] == 1)
                return false;
        }
        int xx = x, yy = y;
        while (xx >= 0 && yy < n) {
            if (qn[xx][yy] == 1)
                return false;
            xx--, yy++;
        }
        xx = x, yy = y;
        while (xx < n && yy >= 0) {
            if (qn[xx][yy] == 1)
                return false;
            xx++, yy--;
        }

        xx = x, yy = y;
        while (xx >= 0 && yy >= 0) {
            if (qn[xx][yy] == 1)
                return false;
            xx--, yy--;
        }
        xx = x, yy = y;
        while (xx < n && yy < n) {
            if (qn[xx][yy] == 1)
                return false;
            xx++, yy++;
        }

        return true;
    }
    void solve(vector<vector<int>> qn, int n, int ind, int& ans) {
        if (ind==n) {
            ans++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (valid(qn, ind, i, n)) {
                qn[ind][i] = 1;
                solve(qn, n, ind + 1, ans);
                qn[ind][i] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<int>> qn(n, vector<int>(n, 0));
        int ans = 0;
        solve(qn, n, 0, ans);
        return ans;
    }
};