/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool DFS(TreeNode* root, vector<TreeNode*>& Node, TreeNode* req) {
    if (root == NULL) {
        return false;
    }
    
    Node.push_back(root);

    if (root->val == req->val) {
        return true;
    }

    if (DFS(root->left, Node, req) || DFS(root->right, Node, req)) {
        return true;
    }

    Node.pop_back();  // Remove the node only if the required node was not found in this path.
    return false;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> p1, p2;
    
    DFS(root, p1, p);
    DFS(root, p2, q);
    
    int pS = p1.size();
    int qS = p2.size();
    TreeNode* lca = nullptr;

    for (int i = 0; i < min(pS, qS); i++) {
        if (p1[i] == p2[i]) {
            lca = p1[i];
        } else {
            break;
        }
    }
    return lca;
}




// OPTIMIzed solution


https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/solutions/5930866/easy-to-understand-solution-for-lowest-common-ancestor-of-a-binary-tree
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if the root is NULL, return NULL
        if (root == NULL) return NULL;

        // If the current node is p or q, return the current node
        if (root == p || root == q) return root;

        // Recur for the left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both left and right are non-NULL, root is the LCA
        if (left != NULL && right != NULL) {
            return root;
        }

        // If only one side returns a result, return that one
        return left != NULL ? left : right;
    }
};