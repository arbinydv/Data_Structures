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

// Insertion in Binary Search Tree using Bottom UP approach without Passing the parent
// T>.c= 0(height) + S.C= 0(height)

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        // Bottom UP approach
        
        if(!root)
        {
            auto node= new TreeNode(val);
            return node;
        }
        
        if(root->val<val)
        {
            root->right=  insertIntoBST(root->right,val);
        }
        if(root->val >val)
        {
            root->left= insertIntoBST(root->left,val);
        }
        return root;
        
    }
};

//Insertion in Binary Search Tree using Top Down Approach
// Complexity is same and no parent is passed.
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
 
    static void insertNode(TreeNode *root,int &val,TreeNode *parent) {
        if(root == NULL) {
            // finding the position to insert node
            if(parent -> val < val) {
                parent -> right = new TreeNode(val);
                return;
            }
            else if(parent -> val > val) {
                parent -> left = new TreeNode(val);
                return;
            }
        }
 
        if(root -> val > val) insertNode(root -> left,val,root);
        if(root -> val < val) insertNode(root -> right,val,root);
    }
 
    TreeNode* insertIntoBST(TreeNode* root, int val) {
 
        if(root == NULL) return new TreeNode(val);
 
        insertNode(root,val,NULL);
 
        return root;
 
    }
};