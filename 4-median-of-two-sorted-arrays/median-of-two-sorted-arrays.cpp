class Solution {
public:
/*
n = mums1.size(), m = nums2.size()
1st while(i < n && j < m)
            i                j
nums1 = [1, 3], nums2 = [2]
         0   1           0
2nd while i < n
   all remaining in merge nuums1 in merge

3nd while j < m
   all remaining in merge nuums2 in merge
Jab odd => 
   merge = [1, 2, 3] n + m % 2 != 0  means odd 
                ^
                |
            merge[mid] / 1.0

even 
           0  1  2  3  
  merge = [1, 2, 3, 4] n + m % 2 == 0  means  even
              ^  ^
              |  |
int mid = merge.lenght() / 2;
            merge[mid] + merge[mid - 1] / 2.0   =  2.5


            tc = O(n) > O(log (n + m))
            Sc = O(n + m)
*/
/*
Heap sort =>
   maxHeap, minheap
*/
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int>maxheap;
        priority_queue<int, vector<int>, greater<int>>minheap;
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        for(int A : nums1){
            if(maxheap.empty()){
                maxheap.push(A);
            }
            else{
                if(maxheap.top() < A){
                    minheap.push(A);
                }
                else{
                    maxheap.push(A);
                }
            }
            if(abs((int)maxheap.size() - (int)minheap.size()) > 1){
                if(maxheap.size() > minheap.size()){
                    minheap.push(maxheap.top());
                    maxheap.pop();
                }
                else{
                    maxheap.push(minheap.top());
                    minheap.pop();
                }
            }
        }
        if((maxheap.size() + minheap.size()) % 2 == 0){
            return (maxheap.top() + minheap.top()) / 2.0;
        }
        if(maxheap.size() > minheap.size())return maxheap.top();
        return minheap.top();
    }
};