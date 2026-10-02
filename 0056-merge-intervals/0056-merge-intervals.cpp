class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            // If current interval is already covered
            if (!ans.empty() && start <= ans.back()[1]) {
                continue;
            }

            for (int j = i + 1; j < n; j++) {
                if (intervals[j][0] <= end) {
                    end = max(end, intervals[j][1]);
                    i = j;  // skip merged intervals
                } 
                else {
                    break;
                }
            }

            ans.push_back({start, end});
        }

        return ans;
    }
};