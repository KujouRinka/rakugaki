func distanceK(root *TreeNode, target *TreeNode, k int) []int {
	var visitTree func(r *TreeNode, depth int, from *TreeNode)
	var result []int
	tar := target
	hashTable := make(map[int]*TreeNode)

	var findParent func(r *TreeNode)
	findParent = func(r *TreeNode) {
		if r.Left != nil {
			hashTable[r.Left.Val] = r
			findParent(r.Left)
		}
		if r.Right != nil {
			hashTable[r.Right.Val] = r
			findParent(r.Right)
		}
	}
	findParent(root)

	visitTree = func(r *TreeNode, depth int, from *TreeNode) {
		if r == nil {
			return
		}
		if depth == k {
			result = append(result, r.Val)
			return
		}

		if r.Left != from {
			visitTree(r.Left, depth+1, r)
		}
		if r.Right != from {
			visitTree(r.Right, depth+1, r)
		}
		if nr, ok := hashTable[r.Val]; ok && nr != from {
			visitTree(nr, depth+1, r)
		}
	}


	visitTree(tar, 0, nil)

	return result
}
