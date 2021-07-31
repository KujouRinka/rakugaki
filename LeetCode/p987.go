func verticalTraversal(root *TreeNode) [][]int {
	hashMap := make(map[int]map[int][]int)
	var visitTree func(root *TreeNode, width, depth int)
	visitTree = func(root *TreeNode, width, depth int) {
		if root == nil {
			return
		}
		if hashMap[width] == nil {
			hashMap[width] = make(map[int][]int)
		}
		hashMap[width][depth] = append(hashMap[width][depth], root.Val)
		visitTree(root.Left, width - 1, depth + 1)
		visitTree(root.Right, width + 1, depth + 1)
	}

	visitTree(root, 0, 0)
	widths := make([]int, 0, len(hashMap))
	result := make([][]int, len(hashMap))
	for key := range hashMap {
		widths = append(widths, key)
	}
	sort.Ints(widths)

	ind := 0
	for _, val := range widths {
		depths := make([]int, 0, len(hashMap[val]))
		for key := range hashMap[val] {
			depths = append(depths, key)
		}
		sort.Ints(depths)
		result[ind] = make([]int, 0, len(hashMap[val]))
		for _, i := range depths {
			sort.Ints(hashMap[val][i])
			result[ind] = append(result[ind], hashMap[val][i]...)
		}
		ind++
	}
	return result
}