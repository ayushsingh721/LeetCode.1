class Solution {
    struct Node {
        int product;
        array<int, 5> count;

        Node(int k = 1) {
            product = 1 % k;
            count.fill(0);
        }
    };

    int n, k;
    vector<int> nums;
    vector<Node> tree;

    Node mergeNodes(const Node& left, const Node& right) {
        Node result(k);

        // Product of the whole segment
        result.product = (left.product * right.product) % k;

        // Non-empty prefixes entirely inside the left segment
        for (int r = 0; r < k; r++) {
            result.count[r] += left.count[r];
        }

        // Prefixes that contain all of left and part of right
        for (int r = 0; r < k; r++) {
            int newRemainder = (left.product * r) % k;
            result.count[newRemainder] += right.count[r];
        }

        return result;
    }

    Node makeLeaf(int value) {
        Node leaf(k);

        int remainder = value % k;
        leaf.product = remainder;
        leaf.count[remainder] = 1;

        return leaf;
    }

    void build(int node, int left, int right) {
        if (left == right) {
            tree[node] = makeLeaf(nums[left]);
            return;
        }

        int mid = (left + right) / 2;
        build(node * 2, left, mid);
        build(node * 2 + 1, mid + 1, right);

        tree[node] = mergeNodes(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int left, int right, int index, int value) {
        if (left == right) {
            tree[node] = makeLeaf(value);
            return;
        }

        int mid = (left + right) / 2;

        if (index <= mid) {
            update(node * 2, left, mid, index, value);
        } else {
            update(node * 2 + 1, mid + 1, right, index, value);
        }

        tree[node] = mergeNodes(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft <= left && right <= queryRight) {
            return tree[node];
        }

        int mid = (left + right) / 2;

        if (queryRight <= mid) {
            return query(node * 2, left, mid, queryLeft, queryRight);
        }

        if (queryLeft > mid) {
            return query(node * 2 + 1, mid + 1, right,
                         queryLeft, queryRight);
        }

        Node leftPart = query(node * 2, left, mid,
                              queryLeft, queryRight);
        Node rightPart = query(node * 2 + 1, mid + 1, right,
                               queryLeft, queryRight);

        return mergeNodes(leftPart, rightPart);
    }

public:
    vector<int> resultArray(vector<int>& numsInput,
                            int kInput,
                            vector<vector<int>>& queries) {
        nums = numsInput;
        k = kInput;
        n = nums.size();

        tree.assign(4 * n, Node(k));
        build(1, 0, n - 1);

        vector<int> answer;

        for (const auto& queryData : queries) {
            int index = queryData[0];
            int value = queryData[1];
            int start = queryData[2];
            int x = queryData[3];

            // This update persists for future queries.
            nums[index] = value;
            update(1, 0, n - 1, index, value);

            // Count prefix products of nums[start..n-1]
            Node result = query(1, 0, n - 1, start, n - 1);

            answer.push_back(result.count[x]);
        }

        return answer;
    }
};