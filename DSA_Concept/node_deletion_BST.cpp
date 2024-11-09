TreeNode* deleteNode(TreeNode* root, int key) {
    // Base case: If the root is NULL, there's nothing to delete, so we return NULL.
    if (root == NULL) {
        return root;
    }
    
    // If the current node's value matches the key, this is the node to delete.
    if (root->val == key) {
        TreeNode* x = root;
        
        // If the node has a right child
        if (root->right != NULL) {
            
            // If the right child has a left child, we rearrange the tree
            if (root->right->left != NULL) {
                TreeNode* y = root->left;          // Store the current left subtree.
                root->left = root->right->left;    // Move the left child of the right subtree to the current left.
                TreeNode* z = root->right->left;
                
                // Move down to the leftmost node in the subtree to attach `y`.
                while (z->left != NULL) {
                    z = z->left;
                }
                z->left = y;                       // Attach `y` at the leftmost position.
                
                root = root->right;                // Replace root with its right child.
                delete x;                          // Delete the original node.
                return root;
                
            // If the right child has no left child, adjust pointers directly.
            } else if (root->right->left == NULL) {
                TreeNode* y = root->left;          // Store the current left subtree.
                root = root->right;                // Replace root with its right child.
                root->left = y;                    // Attach the left subtree.
                delete x;                          // Delete the original node.
                return root;
            }

        // If the node has no right child but has a left child.
        } else {
            if (root->left != NULL) {
                root = root->left;                 // Replace root with its left child.
                delete x;                          // Delete the original node.
                return root;
            }
            // If the node has no children, simply delete it and return NULL.
            if(root->left == NULL && root->right == NULL){
                delete x;
                return NULL;
            }
        }
    }

    // If the key is smaller than the root's value, we search in the left subtree.
    // Important: `root->left = deleteNode(root->left, key);` is used to 
    // update the left child of the current node after a possible deletion.
    // This ensures the BST structure remains correct after deletion.
    if (root->val > key) {
        root->left = deleteNode(root->left, key);
    }

    // If the key is larger than the root's value, we search in the right subtree.
    // Important: `root->right = deleteNode(root->right, key);` is used to 
    // update the right child of the current node after a possible deletion.
    // This is essential to maintain the BST structure, as it reconnects
    // the modified subtree to the current node.
    if (root->val < key) {
        root->right = deleteNode(root->right, key);
    }

    // Finally, return the root node, possibly with modified left or right pointers.
    return root;
}
