class Solution {
    int dp[][][];
    int solve(int[][] grid, int i, int j, int dirr) {
         if (i == grid.length - 1 && j == grid[0].length - 1) {
            return 1;
        }
        if (i < 0 || i >= grid.length ||
                j < 0 || j >= grid[0].length) {
            return 0;
        }
        int a = 0;
        int b = 0;
        if(dp[i][j][dirr] != -1)return dp[i][j][dirr];
        if (grid[i][j] == 1) {
           if(dirr == 1){
              return dp[i][j][dirr] = solve(grid, i + 1, j, 2);
           }
           else{
            return dp[i][j][dirr] = solve(grid, i, j + 1, 1);
           }
        } else {
            a = solve(grid, i + 1, j, 2);
            b = solve(grid, i, j + 1, 1);
        }

        return dp[i][j][dirr] = (a + b) % 1000000007;
    }

    public int uniquePaths(int[][] grid) {
        dp = new int[grid.length][grid[0].length][3];
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j++){
                Arrays.fill(dp[i][j], -1);
            }
        }
        return solve(grid, 0, 0, 2);
    }
}