class Solution {
public:

    struct State {
        long long score;
        array<int, 4> ids;

        State() {
            score = 0;
            ids.fill(INT_MAX);
        }
    };

    // Insert index into already sorted array
    array<int, 4> addIndex(array<int, 4> ids, int x) {

        for (int i = 0; i < 4; i++) {
            if (x < ids[i]) {

                for (int j = 3; j > i; j--) {
                    ids[j] = ids[j - 1];
                }

                ids[i] = x;
                break;
            }
        }

        return ids;
    }

    // Return true if a is better than b
    bool better(const State& a, const State& b) {

        // Higher score is better
        if (a.score != b.score)
            return a.score > b.score;

        // Same score -> lexicographically smaller indices
        return a.ids < b.ids;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        /*
            Store:
            {left, right, weight, original_index}
        */
        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        // Sort according to left endpoint
        sort(a.begin(), a.end());

        /*
            next[i] =
            first interval whose left > a[i].right
        */

        vector<long long> starts(n);

        for (int i = 0; i < n; i++) {
            starts[i] = a[i][0];
        }

        vector<int> next(n);

        for (int i = 0; i < n; i++) {

            next[i] = upper_bound(
                starts.begin(),
                starts.end(),
                a[i][1]
            ) - starts.begin();
        }

        /*
            dp[i][k]:

            Best result starting from interval i
            when we can still choose at most k intervals.
        */

        vector<array<State, 5>> dp(n + 1);

        // dp[n][k] = choose nothing
        for (int k = 0; k <= 4; k++) {
            dp[n][k] = State();
        }

        for (int i = n - 1; i >= 0; i--) {

            // Can't select anything
            dp[i][0] = State();

            for (int k = 1; k <= 4; k++) {

                // -------------------------
                // Option 1: Skip interval i
                // -------------------------

                State skip = dp[i + 1][k];

                // -------------------------
                // Option 2: Take interval i
                // -------------------------

                State take = dp[next[i]][k - 1];

                take.score += a[i][2];

                take.ids = addIndex(
                    take.ids,
                    (int)a[i][3]
                );

                // -------------------------
                // Choose better option
                // -------------------------

                if (better(take, skip))
                    dp[i][k] = take;
                else
                    dp[i][k] = skip;
            }
        }

        // Convert fixed array to vector
        vector<int> ans;

        for (int x : dp[0][4].ids) {

            if (x != INT_MAX)
                ans.push_back(x);
        }

        return ans;
    }
};