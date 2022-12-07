package main

import (
	"bufio"
	"fmt"
	"strings"
	"os"
)

type Stack []string

func (s *Stack) IsEmpty() bool {
	return len(*s) == 0
}

func (s *Stack) Push(str string) {
	*s = append(*s, str)
}

func (s *Stack) Pop() (string, bool) {
	if s.IsEmpty() {
		return "", false
	} else {
		index := len(*s) - 1
		element := (*s)[index]
		*s = (*s)[:index]
		return element, true
	}
}

func main() {
	file, _ := os.Open("inp")
	scanner := bufio.NewScanner(file)
	var stack Stack
	for scanner.Scan() {
		ln := strings.Split(scanner.Text(), " ")
		if ln[0] == "$" {
			if ln[1] == "cd" {
				if ln[2] == ".." {
					stack.Pop()
				} else if ln[2] == "/" {
					for len(stack) > 0 {
						stack.Pop()
					}
				} else {
					stack.Push(ln[2])
				}
			} else if ln[2] == "ls" {
				
			}
		} else {

		}
	}

	for len(stack) > 0 {
		x, y := stack.Pop()
		if y == true {
			fmt.Println(x)
		}
	}
}

