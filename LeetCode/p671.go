/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findSecondMinimumValue(root *TreeNode) int {
	firstMin := root.Val
    secondMin := -1

	var findSecondMin func(root *TreeNode)
	findSecondMin = func(root *TreeNode) {
		if root == nil || (secondMin != -1 && root.Val >= secondMin) {
			return
		}
		if root.Val > firstMin {
			secondMin = root.Val
		}
		findSecondMin(root.Left)
		findSecondMin(root.Right)
	}

	findSecondMin(root)
	return secondMin
}
