
class Solution {

    TreeNode find_success(TreeNode root) {
        if (root.left == null) return root;
        return find_success(root.left);
    }

    TreeNode solve(TreeNode root, int key) {
        if (root == null) return null;

        if (root.val == key) {
            TreeNode temp;

            if (root.right != null) {
                temp = find_success(root.right);
                root.val = temp.val;
                root.right = deleteNode(root.right, temp.val);
                return root;
            }
            else if (root.left != null) {
                temp = root.left;
                while (temp.right != null) {
                    temp = temp.right;
                }

                root.val = temp.val;
                root.left = deleteNode(root.left, temp.val);
                return root;
            }
            else {
                return null;
            }
        }

        if (key < root.val) {
            root.left = solve(root.left, key);
        } else {
            root.right = solve(root.right, key);
        }

        return root;
    }

    public TreeNode deleteNode(TreeNode root, int key) {
        return solve(root, key);
    }
}
