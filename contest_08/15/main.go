package main

import (
    "fmt"
)

// Ваш код здесь
type BinaryTreeNode struct {
	value  int
	left   *BinaryTreeNode
	right  *BinaryTreeNode
	parent *BinaryTreeNode
}

func NewBinaryTreeNode(value int) *BinaryTreeNode {
	node := &BinaryTreeNode{
		value:  value,
		left:   nil,
		right:  nil,
		parent: nil,
	}
	return node
}

func (t *BinaryTreeNode) insertNode(value int) {
	if value < t.value {
		if t.left == nil {
			t.left = NewBinaryTreeNode(value)
			t.left.parent = t
		} else {
			t.left.insertNode(value)
		}
	} else if value > t.value {
		if t.right == nil {
			t.right = NewBinaryTreeNode(value)
			t.right.parent = t
		} else {
			t.right.insertNode(value)
		}
	}
}

func (t *BinaryTreeNode) removeNode(value int) *BinaryTreeNode {
	if t == nil {
		return nil
	}

	if value < t.value {
		t.left = t.left.removeNode(value)
	} else if value > t.value {
		t.right = t.right.removeNode(value)
	} else {
		if t.left == nil {
			return t.right
		} else if t.right == nil {
			return t.left
		}

		maxLeft := t.left.findMax()
		t.value = maxLeft.value
		t.left = t.left.removeNode(maxLeft.value)
	}

	return t
}

func (t *BinaryTreeNode) findNode(value int) *BinaryTreeNode {
	if t == nil || t.value == value {
		return t
	}

	if value < t.value {
		return t.left.findNode(value)
	} else {
		return t.right.findNode(value)
	}
}

func (t *BinaryTreeNode) findMax() *BinaryTreeNode {
	for t.right != nil {
		t = t.right
	}
	return t
}

func (t *BinaryTreeNode) String() string {
	if t == nil {
		return ""
	}

	queue := []*BinaryTreeNode{t}
	output := ""

	for len(queue) > 0 {
		levelSize := len(queue)
		for i := 0; i < levelSize; i++ {
			node := queue[i]
			output += fmt.Sprintf("%d ", node.value)

			if node.left != nil {
				queue = append(queue, node.left)
			}
			if node.right != nil {
				queue = append(queue, node.right)
			}
		}
		queue = queue[levelSize:]
	}

	return output
}
// Конец вашего кода

func main() {
    var count int
    fmt.Scan(&count)
    
    var root *BinaryTreeNode
    for count > 0 {
        var command string
        var value int
        fmt.Scan(&command, &value)
        
        if command == "insert" {
            if root == nil {
                root = NewBinaryTreeNode(value)
            }
            root.insertNode(value)
        }else if command == "remove" {
            root = root.removeNode(value)
        }else if command == "find" {
            fmt.Println(root.findNode(value))
        }
        
        count--
    }
}
