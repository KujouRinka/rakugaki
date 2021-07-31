func pathInZigZagTree(label int) []int {
	stack := getStack(label)
	res := make([]int, stack + 1)

	for label != 0 {
		stack = getStack(label)
		res[stack] = label
		start := getStart(stack)
		end := getEnd(stack)

		other := getOtherSide(label, start, end)
		label = other / 2
	}
	return res
}

func getStack(label int) int {
	var stack int
	for ; label != 0; label, stack = label>>1, stack+1 {
	}
	return stack - 1
}

func getStart(stack int) int {
	return 1 << stack
}

func getEnd(stack int) int {
	return (1 << (stack + 1)) - 1
}

func getOtherSide(label, start, end int) int {
	return start + end - label
}
