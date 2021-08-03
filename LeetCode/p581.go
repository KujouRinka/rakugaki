func findUnsortedSubarray(nums []int) int {
	var front, back int
	numsLen := len(nums)
	back = numsLen - 1

	var wg sync.WaitGroup
	wg.Add(2)
	go func() {
		for front+1 < numsLen && nums[front] <= nums[front+1] {
			front++
		}
		wg.Done()
	}()
	go func() {
		for back-1 >= 0 && nums[back] >= nums[back-1] {
			back--
		}
		wg.Done()
	}()
	wg.Wait()

	fmt.Println(front, back)

	if front >= back {
		return 0
	}

	min := 0x7fffffff
	max := -0x80000000
	for i := front; i <= back; i++ {
		if nums[i] < min {
			min = nums[i]
		}
		if nums[i] > max {
			max = nums[i]
		}
	}

	frontInd := 0
	backInd := numsLen - 1
	for ; frontInd < front && nums[frontInd] <= min; frontInd++ {
	}
	for ; backInd > back && nums[backInd] >= max; backInd-- {
	}


	return backInd - frontInd + 1
}
