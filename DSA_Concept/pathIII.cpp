class Solution {
public:
    
    // Here we define a helper function called DFS (Depth-First Search). 
    // It is our path checker for each node in the tree and determines 
    // the number of paths starting from this node that add up to `ts` (target sum).
    unsigned int DFS(TreeNode* root, int ts) {
        // First, let's check if the root is null.
        // If it is, there's no tree to search, so we simply return 0 paths.
        if (root == NULL) {
            return 0;
        }
        
        unsigned int tc = 0;  // `tc` keeps track of the number of paths with sum = ts.
        
        // Now, let's see if the current node's value is exactly equal to `ts`.
        // If it is, we've found a path (just this node), so we increment `tc`.
        if (root->val == ts) tc++;
        
        // Now we’ll go down the left side of the tree from this node.
        // If `root->val` was, say, part of the solution, maybe other values in the left subtree
        // can complete the path sum we're looking for (`ts - root->val`).
        tc += DFS(root->left, ts - root->val);
        
        // Similarly, we explore the right subtree, checking if paths there
        // also add up to the required sum.
        tc += DFS(root->right, ts - root->val);
        
        // Once we're done with this node and all paths beneath it,
        // we return the count of paths with sum `ts` starting from this node.
        return tc;
    }

    // Now we come to the main function `pathSum`, which will calculate
    // the total number of paths across the entire tree that add up to `targetSum`.
    int pathSum(TreeNode* root, int targetSum) {
        // If there's no root, there are no paths, so return 0.
        if (root == NULL) return 0;
        
        // Here's where we get creative with recursion:
        // 1. We ask `pathSum(root->left, targetSum)` to find the paths in the left subtree.
        // 2. Then we ask `pathSum(root->right, targetSum)` to find the paths in the right subtree.
        // 3. Finally, we use DFS on `root` itself to check for paths starting from `root` 
        //    that add up to `targetSum`.
        //
        // This way, every node gets a chance to be the starting point,
        // and all possible paths are checked recursively.
        
        return pathSum(root->left, targetSum) + pathSum(root->right, targetSum) + DFS(root, targetSum);
    }
};
