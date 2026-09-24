class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int ans= nums[i];
            int sum = 0;
            while (ans > 0) {
                sum += ans % 10;
                ans/= 10;
            }
            if (sum == i) {
                return i;
            }
        }
        return -1;
    }
};