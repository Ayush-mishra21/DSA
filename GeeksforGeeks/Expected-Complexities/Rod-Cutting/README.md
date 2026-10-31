# Rod Cutting

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Platform: GeeksforGeeks](https://img.shields.io/badge/Platform-GeeksforGeeks-blue?style=for-the-badge)
![Status: ACCEPTED](https://img.shields.io/badge/Status-ACCEPTED-success?style=for-the-badge)

## 📋 Problem Details

| Metric | Detail |
| :--- | :--- |
| **Platform** | [GeeksforGeeks](https://www.geeksforgeeks.org/problems/rod-cutting0840/1) |
| **Problem Link** | [View Problem on GeeksforGeeks](https://www.geeksforgeeks.org/problems/rod-cutting0840/1) |
| **Language** | `Int f(int i,int price[],int rodLen,int n,vector<vector<int>>& dp)
{
    // Base Case
    if(rodLen==0) return 0;
    if(i==n) return -1e9;

    if(dp[i][rodLen]!=-1) return dp[i][rodLen];

    // Take or Nottake
    int nottake=f(i+1,price,rodLen,n,dp);
    int take=-1e9;
    if(rodLen>=(i+1))
    take=price[i]+f(i,price,rodLen-(i+1),n,dp);

    // return maximum out of them
    return dp[i][rodLen]=max(take,nottake);
}
int cutRod(int price[], int n) {
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return f(0,price,n,n,dp);
}` |
| **Estimated Time Complexity** | `O(N)` |
| **Estimated Space Complexity** | `O(N^2)` |
| **Topics / Tags** | `Expected Complexities`, `Company TagsGoogle`, `Company Tags`, `Google`, `Topic Tags`, `Arrays`, `Dynamic Programming`, `Related Articles`, `Cutting A Rod Dp 13`, `CodeSync` |
| **Synchronized At** | `Sat, 31 Oct 2026 06:20:20 GMT` |

---

### 💡 Solution Note
Automatically synchronized by **[CodeSync v3.0.0](https://studyit.in)** — Universal Multi-Platform Solution Sync Engine powered by [Studyit.in](https://studyit.in).
