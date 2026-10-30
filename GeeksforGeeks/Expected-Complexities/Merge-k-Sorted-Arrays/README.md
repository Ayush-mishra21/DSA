# Merge k Sorted Arrays

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Platform: GeeksforGeeks](https://img.shields.io/badge/Platform-GeeksforGeeks-blue?style=for-the-badge)
![Status: ACCEPTED](https://img.shields.io/badge/Status-ACCEPTED-success?style=for-the-badge)

## 📋 Problem Details

| Metric | Detail |
| :--- | :--- |
| **Platform** | [GeeksforGeeks](https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1) |
| **Problem Link** | [View Problem on GeeksforGeeks](https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1) |
| **Language** | `Class Solution:
    def mergeArrays(self, mat):
        # Code here
        n, m = len(mat), len(mat[0])
        
        heap = []
        for row in range(n):
            heapq.heappush(heap, (mat[row][0], row, 0)) # num, row, col
        
        res = []    
        while heap:
            num, row, col = heapq.heappop(heap)
            res.append(num)
            
            nr, nc = row, col+1
            if nc < m:
                heapq.heappush(heap, (mat[nr][nc], nr, nc))
                
                
        return res` |
| **Estimated Time Complexity** | `O(N^2)` |
| **Estimated Space Complexity** | `O(N)` |
| **Topics / Tags** | `Expected Complexities`, `Company Tags`, `VMWare`, `Flipkart`, `Amazon`, `Microsoft`, `Citrix`, `Topic TagsArraysSortingHeap`, `Topic Tags`, `Arrays`, `Sorting`, `Heap`, `Related Interview Experiences`, `Related Articles`, `Merge K Sorted Arrays`, `CodeSync` |
| **Synchronized At** | `Fri, 30 Oct 2026 07:15:35 GMT` |

---

### 💡 Solution Note
Automatically synchronized by **[CodeSync v3.0.0](https://studyit.in)** — Universal Multi-Platform Solution Sync Engine powered by [Studyit.in](https://studyit.in).
