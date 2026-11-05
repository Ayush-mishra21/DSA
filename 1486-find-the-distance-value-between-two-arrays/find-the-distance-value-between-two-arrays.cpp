class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for(int A : arr1){
            bool flag = false;
            for(int B : arr2){
                if(abs(A - B) <= d){
                    flag = true;
                    break;
                }
            }
            if(!flag)ans++;
        }
        return ans;
    }
};