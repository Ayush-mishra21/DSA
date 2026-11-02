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
    public List<Integer> postorderTraversal(TreeNode root) {
        if(root == null)return new ArrayList<>();
        Stack<TreeNode>st1 = new Stack<>();
        Stack<TreeNode>st2 = new Stack<>();
        st1.push(root);
        while(!st1.isEmpty()){
            TreeNode temp = st1.peek();
            st1.pop();
            st2.push(temp);
            if(temp.left != null){
                st1.push(temp.left);
            }
            if(temp.right != null){
                st1.push(temp.right);
            }
        }
        List<Integer>ans = new ArrayList<>();
        while(!st2.isEmpty()){
            ans.add(st2.peek().val);
            st2.pop();
        }
        return ans;
    }
}