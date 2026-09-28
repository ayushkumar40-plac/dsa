class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int n = items.size();
        vector<int> prices(n), maxbeauty(n);
        prices[0] = items[0][0];
        maxbeauty[0] = items[0][1];
        for (int i = 1; i < n; i++) {
            prices[i] = items[i][0];
            maxbeauty[i] = max(maxbeauty[i-1], items[i][1]);
        }
        vector<int> ans;
        for (int q : queries) {
            int left = 0, right = n - 1, idx = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (prices[mid] <= q) {
                    idx = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            if (idx == -1) ans.push_back(0);
            else ans.push_back(maxbeauty[idx]);
        }
        return ans;
    }
};
