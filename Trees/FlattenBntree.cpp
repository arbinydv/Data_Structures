// In this problem we are flattening the binary tree into linkedlist in-place
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
    void flatten(TreeNode* root) {

      if(root==NULL) return;

      if(root->left== NULL && root->right== NULL) return;
      //else we will go on flatten the left subtree
      flatten(root->left);
      flatten(root->right);

      //cutting the left part and joining it in root->right and before that we store it
      // the right child of root at ith level is then joined with the joined left subtree
      if(root->left)  // if left exist
      {
        TreeNode* temp= root->left;  // store
        while(temp->right)    // we will go till the last child of that left subtree
        {
          temp=temp->right;
        }
        //now join the right subtree
        temp->right= root->right;
        root->right=root->left;
        root->left= NULL;  // assigning the null to all the left child after skeweing
      }
    }
};
