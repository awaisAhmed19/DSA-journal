
#include <iostream>
#include <map>
#include <stack>
#include <vector>

std::vector<int> good_node;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void dfs(std::stack<TreeNode*>& stk, TreeNode* root) {
    std::map<TreeNode*, bool> visited;
    stk.push(root);
    good_node.push_back(root->val);
    while (!stk.empty()) {
        int prev_node = stk.top()->val;
        TreeNode* node = stk.top();
        if (node->left != nullptr && !visited[node->left]) {
            if (prev_node < node->left->val) {
                good_node.push_back(node->left->val);
            }
            stk.push(node->left);
        } else if (node->right != nullptr && !visited[node->right]) {
            if (prev_node < node->right->val) {
                good_node.push_back(node->left->val);
            }
            stk.push(node->right);
        } else {
            std::cout << node->val << " ";
            visited[node] = true;
            stk.pop();
        }
    }
}

TreeNode* build(int arr[], int n, int i = 0) {
    if (i >= n) return nullptr;
    TreeNode* node = new TreeNode(arr[i]);
    node->left = build(arr, n, 2 * i + 1);
    node->right = build(arr, n, 2 * i + 2);

    return node;
}

void post_order(TreeNode* root) {
    if (root == nullptr) return;
    post_order(root->left);
    post_order(root->right);
    std::cout << root->val << " ";
}

int main() {
    std::stack<TreeNode*> stk;
    int arr[] = {2, 1, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode* root = build(arr, n, 0);
    post_order(root);
    std::cout << std::endl;
    dfs(stk, root);
}
