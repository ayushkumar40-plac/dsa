class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> output;
        solve(nums, 0, output, result);
        return result;
    }
    
private:
    void solve(vector<int>& nums, int start, vector<int>& output, vector<vector<int>>& result) {
        result.push_back(output);
        
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            
            output.push_back(nums[i]);
            solve(nums, i + 1,output, result);
            output.pop_back(); 
        }
    }
};
