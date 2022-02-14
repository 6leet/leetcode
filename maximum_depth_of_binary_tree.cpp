#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else if (root->left == NULL && root->right == NULL) {
            return 1;
        }
        int leftDepth = maxDepth(root->left), rightDepth = maxDepth(root->right);
        int Depth = max(leftDepth, rightDepth);
        return Depth + 1;   
    }
};

int main() {

}