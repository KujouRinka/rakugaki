func complexNumberMultiply(num1 string, num2 string) string {
	var real1, imag1 int
	var real2, imag2 int
	fmt.Sscanf(num1, "%d+%di", &real1, &imag1)
	fmt.Sscanf(num2, "%d+%di", &real2, &imag2)
	nReal := real1*real2 - imag1*imag2
	nImag := real1*imag2 + real2*imag1
	return fmt.Sprintf("%d+%di", nReal, nImag)
}

