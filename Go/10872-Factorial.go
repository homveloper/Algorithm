package main

import (
	"bufio"
	"fmt"
	"os"
)

func Factorial(N int) int {
	if N <= 1 {
		return 1
	}

	return Factorial(N-1) * N
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	writer.Flush()

	var N int
	fmt.Fscanln(reader, &N)
	fmt.Fprintln(writer, Factorial(N))
	writer.Flush()
}
