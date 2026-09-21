class Solution {
public:
    vector<int> ans;

    void mergeSort(vector<pair<int,int>>& a, int left, int right) {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;

        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        vector<pair<int,int>> temp;

        int i = left;
        int j = mid + 1;
        int smaller = 0;

        while (i <= mid && j <= right) {

            if (a[j].first < a[i].first) {
                smaller++;
                temp.push_back(a[j]);
                j++;
            }
            else {
                ans[a[i].second] += smaller;
                temp.push_back(a[i]);
                i++;
            }
        }

        while (i <= mid) {
            ans[a[i].second] += smaller;
            temp.push_back(a[i]);
            i++;
        }

        while (j <= right) {
            temp.push_back(a[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); k++) {
            a[left + k] = temp[k];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        ans.assign(n, 0);

        vector<pair<int,int>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({nums[i], i});
        }

        mergeSort(a, 0, n - 1);

        return ans;
    }
};