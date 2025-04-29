/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        long prev = LONG_MIN;
            bool isValid = true;

                void inorder(TreeNode* root) {
                        if (!isValid || !root) return;

                                if (root->left) inorder(root->left);

                                        if (prev >= root->val) {
                                                    isValid = false;
                                                                return;
                                                                        }
                                                                                prev = root->val;

                                                                                        if (root->right) inorder(root->right);
                                                                                            }

                                                                                                bool isValidBST(TreeNode* root) {
                                                                                                        prev = LONG_MIN; // Reset prev for each call
                                                                                                                isValid = true;  // Reset isValid for each call
                                                                                                                        inorder(root);
                                                                                                                                return isValid;
                                                                                                                                    }
                                                                                                                                    };
