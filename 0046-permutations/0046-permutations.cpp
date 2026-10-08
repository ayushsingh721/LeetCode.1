class Solution {
public:
    void solve(vector<int>&nums,vector<bool>&used,vector<int>&current,
    vector<vector<int>>&ans){

        if(current.size() == nums.size()){
            ans.push_back(current);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(used[i])
                continue;

            used[i] = true;
            current.push_back(nums[i]);

            solve(nums,used,current,ans);

            current.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;
        vector<bool> used(nums.size(), false);
        vector<vector<int>> ans;

        solve(nums,used,current,ans);

        return ans;
    }
};