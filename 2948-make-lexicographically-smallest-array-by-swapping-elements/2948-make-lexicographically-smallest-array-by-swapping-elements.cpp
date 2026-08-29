class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        // Store {value, original index}
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // Sort by value
        sort(arr.begin(), arr.end());

        vector<int> ans(n);

        int start = 0;

        while (start < n) {
            int end = start;

            // Find all values belonging to the same group
            while (end + 1 < n &&
                   arr[end + 1].first - arr[end].first <= limit) {
                end++;
            }

            // Get original indices of this group
            vector<int> indices;

            for (int i = start; i <= end; i++) {
                indices.push_back(arr[i].second);
            }

            // Original indices must be sorted
            sort(indices.begin(), indices.end());

            // Values are already sorted
            for (int i = 0; i < (int)indices.size(); i++) {
                ans[indices[i]] = arr[start + i].first;
            }

            start = end + 1;
        }

        return ans;
    }
};