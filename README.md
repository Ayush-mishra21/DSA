<div align="center">

# ⚡ Data Structures & Algorithms Solutions

[![Download CodeSync](https://img.shields.io/badge/Download%20Extension-CodeSync-6366F1?style=for-the-badge&logo=googlechrome&logoColor=white)](https://studyit.in/codesync)
[![Visit Studyit](https://img.shields.io/badge/University%20Notes%20%26%20PYQs-Studyit.in-10B981?style=for-the-badge&logo=book&logoColor=white)](https://studyit.in)
[![Total Solved](https://img.shields.io/badge/Total%20Solved-20-F59E0B?style=for-the-badge&logo=codeforces&logoColor=white)](#-problem-solving-statistics)

<p align="center">
  <a href="https://studyit.in/codesync"><b>📥 Download CodeSync Extension</b></a> •
  <a href="https://studyit.in"><b>🎓 Visit Studyit.in (Semester Notes & Solved PYQ Bank)</b></a>
</p>

> Automated repository containing curated solutions, detailed notes, and complexity breakdowns for Data Structures & Algorithms and Competitive Programming problems, synchronized in real time via **[CodeSync](https://studyit.in/codesync)**.

</div>

---

> [!TIP]
> 🚀 **Automate Your DSA Portfolio:** Download [CodeSync for Chrome](https://studyit.in/codesync) to sync your submissions from LeetCode, GeeksforGeeks, and HackerRank instantly to GitHub.  
> 📚 **Ace University Exams:** Check out [Studyit.in](https://studyit.in) for curated university notes, formula cheat-sheets, and solved past-year question (PYQ) banks mapped to your semester curriculum.

## 📊 Problem Solving Statistics

<div align="center">

[![Easy](https://img.shields.io/badge/Easy-2-00B8A3?style=flat-square&logo=leetcode&logoColor=white)](#-difficulty-breakdown)
[![Medium](https://img.shields.io/badge/Medium-9-FFC01E?style=flat-square&logo=leetcode&logoColor=white)](#-difficulty-breakdown)
[![Hard](https://img.shields.io/badge/Hard-3-FF375F?style=flat-square&logo=leetcode&logoColor=white)](#-difficulty-breakdown)

</div>

### 🎯 Difficulty Breakdown

| Difficulty | Solved | Percentage | Progress Bar |
| :--- | :---: | :---: | :--- |
| 🟢 **Easy** | `2` | `14%` | `██░░░░░░░░░░░░` |
| 🟡 **Medium** | `9` | `64%` | `█████████░░░░░` |
| 🔴 **Hard** | `3` | `21%` | `███░░░░░░░░░░░` |

### 🌐 Platform Breakdown

| Platform | Solved | Status | Link |
| :--- | :---: | :---: | :---: |
| 🟡 **LeetCode** | `15` | 🟢 Active | [leetcode.com](https://leetcode.com) |
| 🟢 **GeeksforGeeks** | `2` | 🟢 Active | [geeksforgeeks.org](https://practice.geeksforgeeks.org) |
| 🔴 **TakeUForward** | `0` | 🟢 Active | [takeuforward.org](https://takeuforward.org) |
| 🔵 **HackerRank** | `0` | 🟢 Active | [hackerrank.com](https://hackerrank.com) |
| 🟤 **CodeChef** | `0` | 🟢 Active | [codechef.com](https://codechef.com) |
| 🟣 **Codeforces** | `0` | 🟢 Active | [codeforces.com](https://codeforces.com) |

### 📌 Recent Activity

| Metric | Details |
| :--- | :--- |
| **Latest Solved** | **Rod Cutting** |
| **Platform** | `GeeksforGeeks` |
| **Difficulty** | `Easy` |
| **Language** | `int f(int i,int price[],int rodLen,int n,vector<vector<int>>& dp)
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
| **Last Synchronized** | `Sat, 31 Oct 2026 06:20:22 GMT` |

---

## 📂 Repository Structure

The solutions in this repository are automatically structured and categorized:

```text
├── LeetCode/
│   └── [Topic]/[Problem-Title]/
│       ├── solution.[ext]
│       └── README.md
├── GeeksforGeeks/
│   └── [Topic]/[Problem-Title]/
│       ├── solution.[ext]
│       └── README.md
├── TakeUForward/
│   └── ...
├── stats.json          # Raw real-time statistics
└── README.md           # This dashboard
```

---

## 🚀 About CodeSync & Studyit

This repository is maintained automatically using **[CodeSync](https://studyit.in/codesync)** — built by **[Studyit.in](https://studyit.in)**.

- ⚡ **[CodeSync](https://studyit.in/codesync):** A lightweight, high-performance browser extension that automatically captures and syncs your accepted code submissions directly to your GitHub repository across 6+ competitive programming platforms with zero manual effort.
- 🎓 **[Studyit.in](https://studyit.in):** The smarter exam-preparation platform tailored for engineering and university students. Access curated unit-wise notes, formula cards, recurrence patterns, and comprehensive solved Previous Year Question (PYQ) banks mapped directly to your university curriculum.

### ✨ Key Highlights
- ⚡ **Zero Friction:** Auto-syncs upon submission without manual copy-pasting.
- 📁 **Organized Hierarchies:** Automatically categorizes by platform, difficulty, and algorithmic topic.
- 📝 **Rich READMEs:** Generates problem descriptions, links, and Big-O time/space complexity estimates.
- 📊 **Dynamic Stats:** Maintains `stats.json` and updates repo documentation automatically.

🔗 **Download CodeSync:** [studyit.in/codesync](https://studyit.in/codesync)  
🌐 **Visit Studyit Platform:** [studyit.in](https://studyit.in)  
💡 *Crafted with ❤️ by developers, for students and developers.*
