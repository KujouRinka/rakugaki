func visiblePoints(points [][]int, angle int, location []int) int {
	var selfPoints int
	var angles []float64
	x0, y0 := location[0], location[1]
	for _, point := range points {
		if point[0] == location[0] && point[1] == location[1] {
			selfPoints++
			continue
		}
		ang := math.Atan2(float64(point[0]-x0), float64(point[1]-y0))
		angles = append(angles, ang, ang+2*math.Pi)
	}
	sort.Float64s(angles)
	fac := 180 / math.Pi
	var maxPoints int
	for pFront, pBack := 0, 0; pBack < len(angles); {
		if (angles[pBack]-angles[pFront])*fac <= float64(angle) {
			pBack++
		} else {
			pFront++
		}
		maxPoints = max(maxPoints, pBack-pFront)
	}
	return maxPoints + selfPoints
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

