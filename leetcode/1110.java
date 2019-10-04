/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    
    private HashSet<TreeNode> solve(TreeNode p, HashSet<Integer> to_delete){
        if (p == null) return new HashSet<>();
        Set<TreeNode> left_set= solve(p.left, to_delete);
        Set<TreeNode> right_set= solve(p.right, to_delete);
        if (p.left != null && to_delete.contains(p.left.val)) p.left = null;
        if (p.right!= null && to_delete.contains(p.right.val)) p.right= null;

        HashSet<TreeNode> result = new HashSet<>();
        result.addAll(left_set);
        result.addAll(right_set);

        if (!to_delete.contains(p.val)){
            if (p.left != null) result.remove(p.left);
            if (p.right!= null) result.remove(p.right);
            result.add(p);
        }

        return result;
    }

    public List<TreeNode> delNodes(TreeNode root, int[] td) {
        HashSet<Integer> to_delete = new HashSet();
        for (int x : td) to_delete.add(x);
        Set<TreeNode> resultSet = solve(root, to_delete);
        List<TreeNode> resultList = new LinkedList();
        for (TreeNode e : resultSet)
            resultList.add(e);
        return resultList;
    }
    
}
