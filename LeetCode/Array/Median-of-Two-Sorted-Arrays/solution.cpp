class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums, vector<int>& nums2) {
        vector<int> nums1 = nums;
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        priority_queue<int> pqmax;
        priority_queue<int, vector<int>, greater<int>> pqmin;
        for (int A : nums1) {
            if (pqmax.empty()) {
                pqmax.push(A);
            } else {
                if (A > pqmax.top()) {
                    pqmin.push(A);
                } else {
                    pqmax.push(A);
                }
            }
            if (abs((int)pqmax.size() - (int)pqmin.size()) > 1) {
                if (pqmax.size() > pqmin.size()) {
                    pqmin.push(pqmax.top());
                    pqmax.pop();
                } else {
                    pqmax.push(pqmin.top());
                    pqmin.pop();
                }
            }
        }
        if (nums1.size() % 2 == 0) {
            return (pqmax.top() + pqmin.top()) / 2.0;
        }

        if (pqmax.size() > pqmin.size())
            return pqmax.top();

        return pqmin.top();
    }
};