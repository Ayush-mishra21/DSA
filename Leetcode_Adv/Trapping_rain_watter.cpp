class Solution {
    public:
        //total water is trapped into the bars
        int trap(vector<int>& h) {
            int l=0,r=h.size()-1,lmax=INT_MIN,rmax=INT_MIN,ans=0;
            while(l<r){
                lmax=max(lmax,h[l]);
                rmax=max(rmax,h[r]);
                ans+=(lmax<rmax)?lmax-h[l++]:rmax-h[r--];
            }
            return ans;
        }
    };
}
instead of computing the left and right parts separately, we may think of some way to do it in one iteration.

Suppose we start from both the left and right end by maintaining two pointers left and right. If the smaller tower is at the left end, water trapped would be dependent on the tower's height in the direction from left to right. Similarly, if the tower at the right end is smaller, water trapped would be dependent on the tower's height in the direction from right to left. So we first calculate water trapped on the smaller tower among height[left] and height[right] and move the pointer associated with the smaller tower.

Loop will run till the left pointer doesn't cross the right pointer. In terms of an analogy, we can think of height[left] and height[right] as a wall of a partial container where we fix the higher end and flow water from the lower end.