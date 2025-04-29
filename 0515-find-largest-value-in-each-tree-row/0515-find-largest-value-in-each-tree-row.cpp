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
              vector<int> largestValues(TreeNode* root) {
                      if (!root) return {};// edge case
                              queue<TreeNode*> q;
                                      q.push(root);
                                              vector<int> arr;
                                                      for(int level=0; !q.empty(); level++){
                                                                  int qz=q.size();
                                                                              arr.push_back(INT_MIN);
                                                                                          for(int i=0; i<qz; i++){
                                                                                                          auto Node=q.front();
                                                                                                                          q.pop();
                                                                                                                                          arr[level]=max(arr[level], Node->val);
                                                                                                                                                          if (Node->left) q.push(Node->left);
                                                                                                                                                                          if (Node->right) q.push(Node->right);
                                                                                                                                                                                      }
                                                                                                                                                                                              }
                                                                                                                                                                                                      return arr;
                                                                                                                                                                                                          }
                                                                                                                                                                                                          };/**
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
