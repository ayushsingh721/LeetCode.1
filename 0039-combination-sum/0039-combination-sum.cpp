class Solution {
public:

    void solve(int start, vector<int>&candidates,int target,vector<int>& current, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(current);
            return;
        }

        for(int i = start; i < candidates.size();i++){
            if(candidates[i] > target){
                return;
            }
            current.push_back(candidates[i]);

            solve(i, candidates, target - candidates[i], current,ans);

            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> ans;

        sort(candidates.begin(),candidates.end());

        solve(0, candidates, target,current, ans);

        return ans;
    }
};