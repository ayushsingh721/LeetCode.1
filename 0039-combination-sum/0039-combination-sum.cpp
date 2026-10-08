class Solution {
public:
    void solve(int start, vector<int>& candidates, int target,
               vector<int>& current, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            if (candidates[i] > target)
                continue;

            // Choose
            current.push_back(candidates[i]);

            // Same i -> can reuse element
            solve(i, candidates, target - candidates[i],
                  current, ans);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) {

        vector<vector<int>> ans;
        vector<int> current;

        sort(candidates.begin(), candidates.end());

        solve(0, candidates, target, current, ans);

        return ans;
    }
};