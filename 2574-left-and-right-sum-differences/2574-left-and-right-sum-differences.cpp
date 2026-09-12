class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int total = 0;

        for (int x : nums)
            total += x;

        vector<int> ans;
        int leftSum = 0;

        for (int x : nums) {
            int rightSum = total - leftSum - x;

            ans.push_back(abs(leftSum - rightSum));

            leftSum += x;
        }

        return ans;
    }
};