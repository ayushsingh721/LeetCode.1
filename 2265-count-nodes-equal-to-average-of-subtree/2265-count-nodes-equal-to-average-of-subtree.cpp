class Solution {
public:
    int ans = 0;

    pair<int, int> dfs(TreeNode* node) {
        if (node == nullptr)
            return {0, 0};

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        int sum = left.first + right.first + node->val;
        int count = left.second + right.second + 1;

        if (node->val == sum / count)
            ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

