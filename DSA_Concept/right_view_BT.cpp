# using BFS


// Function to perform BFS traversal and get the right side view of the tree
void bfs(TreeNode* root, vector<int>& v) {
    // If the root is NULL, there's nothing to process
    if (root == NULL) {
        return;
    }

    // Queue to facilitate level-order traversal
    queue<TreeNode*> q;
    q.push(root); // Start with the root node

    // Loop through each level of the tree
    while (!q.empty()) {
        int size = q.size(); // Number of nodes at the current level
        int vl; // Variable to store the value of the rightmost node at each level

        // Process all nodes at the current level
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); // Get the front node in the queue
            q.pop(); // Remove it from the queue

            vl = node->val; // Update vl with the current node's value (will hold the rightmost node's value by the end of the loop)

            // If the node has a left child, add it to the queue
            if (node->left != NULL) {
                q.push(node->left);
            }

            // If the node has a right child, add it to the queue
            if (node->right != NULL) {
                q.push(node->right);
            }
        }

        // After finishing the level, add the rightmost node's value to the result vector
        v.push_back(vl);
    }
}

// Function to return the right side view of a binary tree
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans; // Vector to store the right side view of the tree
    bfs(root, ans); // Perform BFS to populate ans with the right side view
    return ans; // Return the result
}


##DFS


// Helper function to get the right side view of the tree
void get(TreeNode* root, vector<int>& ans, int cnt) {
    // Base case: If the node is NULL, return
    if (!root) return;

    // If the current level hasn't been added to ans yet, add the node's value
    if (ans.size() < cnt) {
        ans.push_back(root->val);
    } else {
        // Otherwise, update the value at this level with the current node's value (rightmost)
        ans[cnt - 1] = root->val;
    }

    // Recursively process the left subtree, increasing the level counter
    get(root->left, ans, cnt + 1);

    // Recursively process the right subtree, also increasing the level counter
    get(root->right, ans, cnt + 1);
}

// Public function to return the right side view of a binary tree
public:
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans; // Vector to store the right side view of the tree
    get(root, ans, 1); // Call the helper function with level 1
    return ans; // Return the right side view result
}


# Better then last one

pair<int, int> ans = {INT_MIN, 0};

// Optimized BFS function
void BFS(TreeNode* root) {
    if (root == NULL) return;

    queue<TreeNode*> q;
    q.push(root);
    int level = 1; // Start with the first level

    // Perform BFS traversal
    while (!q.empty()) {
        int temp = 0;  // Sum for the current level
        int levelSize = q.size(); // Number of nodes at the current level

        // Process each node at the current level
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            temp += node->val; // Accumulate the sum of values

            // Add children to the queue
            if (node->left != NULL) q.push(node->left);
            if (node->right != NULL) q.push(node->right);
        }

        // Update the maximum sum and corresponding level
        if (temp > ans.first) {
            ans.first = temp; // Update max sum
            ans.second = level; // Update level for max sum
        }

        level++; // Move to the next level
    }
}

// Function to return the level with the maximum sum
int maxLevelSum(TreeNode* root) {
    BFS(root);
    return ans.second; // Return the level with the maximum sum
}
