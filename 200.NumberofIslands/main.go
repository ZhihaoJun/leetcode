package main

import (
	"fmt"
)

type UnionFind struct {
	n       int
	sets    []int
	weights []int
	setsN   int
}

func New(n int) *UnionFind {
	ret := &UnionFind{
		n:       n,
		sets:    make([]int, n),
		weights: make([]int, n),
		setsN:   n,
	}
	for i := 0; i < n; i++ {
		ret.sets[i] = i
		ret.weights[i] = 1
	}
	return ret
}

func (this *UnionFind) Num() int {
	return this.n
}

func (this *UnionFind) SetsNum() int {
	return this.setsN
}

func (this *UnionFind) Find(n int) int {
	for n != this.sets[n] {
		this.sets[n] = this.sets[this.sets[n]]
		n = this.sets[n]
	}
	return n
}

func (this *UnionFind) IsSameSet(a int, b int) bool {
	return this.Find(a) == this.Find(b)
}

func (this *UnionFind) Union(a int, b int) *UnionFind {
	ra := this.Find(a)
	rb := this.Find(b)
	if ra == rb {
		return this
	}
	if this.weights[ra] < this.weights[rb] {
		this.sets[ra] = rb
		this.weights[rb] += this.weights[ra]
	} else {
		this.sets[rb] = ra
		this.weights[ra] += this.weights[rb]
	}
	this.setsN -= 1
	return this
}

func left(grid [][]byte, x, y int) byte {
	if x == 0 {
		return '\000'
	}
	return grid[x-1][y]
}

func up(grid [][]byte, x, y int) byte {
	if y == 0 {
		return '\000'
	}
	return grid[x][y-1]
}

func numIslands(grid [][]byte) int {
	m := len(grid)
	n := len(grid[0])
	uf := New(m * n)

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
      
		}
	}
}

func main() {
	islands := [][]byte{}
	fmt.Println(numIslands(islands))
}
