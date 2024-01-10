package main

import (
    "fmt"
)

type Stack interface{
    empty() bool
    push(r rune)
    top() rune
    pop() rune
}

// Ваш код здесь
type simplestack struct {
    data []rune
}

func NewSimpleStack() *simplestack {
    return &simplestack{}
}

func (s *simplestack) empty() bool {
    return len(s.data) == 0
}

func (s *simplestack) push(r rune) {
    s.data = append(s.data, r)
}

func (s *simplestack) top() rune {
    if len(s.data) == 0 {
        return 0
    }
    return s.data[len(s.data)-1]
}

func (s *simplestack) pop() rune {
    if len(s.data) == 0 {
        return 0
    }
    popItem := s.data[len(s.data)-1]
    s.data = s.data[:len(s.data)-1]
    return popItem
}
// Конец вашего кода

func bracketValidator(stack Stack, str string) bool{
    mapping := map[rune]rune{
        ')': '(',
        ']': '[',
        '}': '{',
    }

    for _, char := range str {
        if char == '(' || char == '[' || char == '{' {
            stack.push(char)
        } else if char == ')' || char == ']' || char == '}' {
            if stack.empty() || stack.top() != mapping[char] {
                return false
            }
            stack.pop()
        }
    }

    return stack.empty()
}

func main() {
    var input string
    fmt.Scan(&input)
    fmt.Println(bracketValidator(NewSimpleStack(), input))
}
