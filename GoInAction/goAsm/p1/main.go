package main

import (
	"GoPrac/src/pkg"
	"fmt"
)


func main() {
	fmt.Println(pkg.Int32Value)
	fmt.Println(pkg.Uint32Value)
	fmt.Println(pkg.Float32Value)
	fmt.Println(pkg.Float64Value)
	fmt.Println(pkg.NumSlice)
	fmt.Println(pkg.BoolValue)
	fmt.Println(pkg.TrueValue)
	fmt.Println(pkg.FalseValue)
	fmt.Println(pkg.HelloWorld, "\twith len:", len(pkg.HelloWorld))
	fmt.Println(string(pkg.AsmSlice), "\twith len and cap:", len(pkg.AsmSlice), cap(pkg.AsmSlice))

}
