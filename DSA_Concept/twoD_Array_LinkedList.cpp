Given a Matrix mat of n*n size. Your task is constructing a 2D linked list representation of the given matrix.

Input: mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
Output: 









Solution Breakdown:

Node Creation: Every matrix element is converted into a node.
Linking: Nodes are connected to their right neighbors and downward neighbors.
Time Complexity (TC):

O(n²): Two nested loops traverse the matrix twice — first for creating nodes and then for linking them.
Space Complexity (SC):

O(n²): An additional 2D array of pointers (dp) is used, plus the space for the n² nodes.
class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        int n = mat.size();

        //2D Matrix of Node pointers
        vector<vector<Node*>> dp(n, vector<Node*>(n));

        // Store each element 
        //In 2D Matrix of Node pointers

        //Right and down pointers 
        //of each Node are still NULL
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = new Node(mat[i][j]);
            }
        }

        // Link the nodes: right and down
        //j==n-1 means end of columns
        //i==n-1 means end of rows
        // if end of columns RIGHT point to NULL
        // if end of rows DOWN point to NULL
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j]->right = (j == n-1) ? nullptr : dp[i][j+1];
                dp[i][j]->down  = (i == n-1) ? nullptr : dp[i+1][j];
            }
        }

        return dp[0][0]; // Return the head of the linked matrix
    }
};