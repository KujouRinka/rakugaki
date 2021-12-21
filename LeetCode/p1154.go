func dayOfYear(date string) int {
	t, _ := time.Parse("2006-01-02", date)
	t2, _ := time.Parse("2006-01-02", strconv.Itoa(t.Year())+"-01-01")
	return int((t.Sub(t2).Hours())/24) + 1
}

