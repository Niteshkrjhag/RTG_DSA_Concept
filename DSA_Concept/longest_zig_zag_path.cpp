/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public void dfs(TreeNode curr, String path, int count){
        if(curr == null){
            return;
        }


        if(count > max){
            max = count;
        }


        if(path == "right" || path == ""){
            dfs(curr.left, "left", count+1);
        }else{
            dfs(curr.left, "left", 1);
        }


        if(path == "left" || path == ""){
            dfs(curr.right, "right", count + 1);
        }else{
            dfs(curr.right, "right", 1);
        }
        
    }

    int max = 0;
    public int longestZigZag(TreeNode root) {
        String path = "";
        dfs(root, path, 0);

        return max;
    }
}