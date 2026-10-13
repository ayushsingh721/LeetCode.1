
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            nums[i] = abs(nums[i]);
        }

        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());

        long long res = 0;

        for (int i = 0; i < n / 2; i++) {
            res -= 1LL * nums[i] * nums[i];
        }

        for (int i = n / 2; i < n; i++) {
            res += 1LL * nums[i] * nums[i];
        }

        return res;
    }
};
