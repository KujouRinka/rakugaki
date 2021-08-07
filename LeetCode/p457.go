func circularArrayLoop(nums []int) bool {
	numsLen := len(nums)

	var nextCursor func(current, step int) int
	nextCursor = func(current, step int) int {
		t := (current + nums[current]) % numsLen
		if t < 0 {
			t = (t + numsLen) % numsLen
		}

		if step == 1 {
			return t
		}
		return nextCursor(t, step-1)
	}

	for i, step := range nums {
		if step == 0 {
			continue
		}
		slow := i
		fast := nextCursor(i, 1)

		for {
			if nums[slow]*nums[fast] <= 0 ||
				nums[slow]*nums[nextCursor(fast, 1)] <= 0 ||
				fast == nextCursor(fast, 1) {
				for i != fast {
					tmp := i
					i = nextCursor(i, 1)
					nums[tmp] = 0
				}
				break // diff sign
			}
			if slow == fast {
				return true
			}
			slow = nextCursor(slow, 1)
			fast = nextCursor(fast, 2)
		}
	}
	return false
}
