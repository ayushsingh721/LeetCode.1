
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        vector<long long> freq(100001, 0);

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            freq[d]++;
        }

        long long k = (long long)k1 + k2;

        for (int d = 100000; d > 0 && k > 0; d--) {
            long long count = freq[d];

            if (count == 0)
                continue;

            if (k >= count) {
                k -= count;
                freq[d - 1] += count;
                freq[d] = 0;
            } else {
                freq[d] -= k;
                freq[d - 1] += k;
                k = 0;
            }
        }

        long long ans = 0;

        for (int d = 1; d <= 100000; d++) {
            ans += freq[d] * d * d;
        }

        return ans;
    }
};
