package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
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

func (s *Stack) Top() string {
    if s.IsEmpty() {
        return ""
    } else {
        index := len(*s) - 1
        element := (*s)[index]
        return element
    }
}

func (s *Stack) Clear() {
    *s = nil
}

func (s *Stack) Print() {
    var temp Stack
    for len(*s) > 0 {
        x, _ := s.Pop()
        temp.Push(x)
    }
    for len(temp) > 0 {
        x, _ := temp.Pop()
        fmt.Printf("%s ", x)
        s.Push(x)
    }
    fmt.Println()
}

func main() {
    file, _ := os.Open("inp")
    // file, _ := os.Open("inpexample")
    scanner := bufio.NewScanner(file)
    m := make(map[string]bool)
    vals := make(map[string]int)
    czytac := true
    pth := "/guard"
    var stack Stack
    stack.Push("guard")
    var temp Stack
    i := 1
    for scanner.Scan() {
        i++
        ln := strings.Split(scanner.Text(), " ")
        if ln[0] == "$" {
            if ln[1] == "cd" {
                czytac = true
                if ln[2] == ".." {
                    for pth[len(pth)-1] != '/' {
                        pth = pth[:len(pth)-1]
                    }
                    pth = pth[:len(pth)-1]
                    stack.Pop()
                } else if ln[2] == "/" {
                    pth = "/guard"
                    for len(stack) > 0 {
                        stack.Pop()
                    }
                    stack.Push("guard")
                } else {
                    pth += "/" + ln[2]
                    stack.Push(ln[2])
                }
            } else if ln[1] == "ls" {
                if m[pth] {
                    czytac = false
                } else {
                    czytac = true
                    m[pth] = true
                }
            }
        } else if ln[0] != "dir" {
            if czytac {
                temp.Clear()
                for len(stack) > 0 {
                    x, _ := stack.Pop()
                    temp.Push(x)
                    mark, _ := strconv.Atoi(ln[0])
                    vals[pth] += mark
                    for pth[len(pth)-1] != '/' {
                        pth = pth[:len(pth)-1]
                    }
                    pth = pth[:len(pth)-1]
                }
                for len(temp) > 0 {
                    x, _ := temp.Pop()
                    pth += "/" + x
                    stack.Push(x)
                }
            }
        }
    }
    used := vals["/guard"]
    free := 70000000 - used
    aktval := 2147483647
    fmt.Println(used)

    for _, element := range vals {
        if free+element >= 30000000 {
            if aktval > element {
                aktval = element
            }
        }
    }
    fmt.Println(aktval)
}
