package main

import (
	"math/rand"
	"time"
)

const (
	PipeStartX    = 68
	PipeResetX    = 9
	PipeWidth     = 8
	ScoreX        = 34
)

func getPipeGap(score int) int {
	switch {
	case score < 5:
		return 13
	case score < 10:
		return 12
	case score < 20:
		return 11
	default:
		return 10
	}
}

func getTickMS(score int, counter int) int {
	if counter <= 25 {
		return 100
	}
	switch {
	case score < 5:
		return 100
	case score < 10:
		return 90
	case score < 20:
		return 80
	default:
		return 70
	}
}

type Pipe struct {
	X           int
	PrevX       int
	TopHeight   int
	BottomY     int
	Scored      bool
	GroundPhase int
}

func init() {
	rand.Seed(time.Now().UnixNano())
}

func NewPipe() *Pipe {
	return &Pipe{}
}

func (p *Pipe) ResetWithGap(gap int) {
	p.X = PipeStartX
	p.PrevX = PipeStartX

	minTop := 2
	maxTop := 25 - gap - 2
	if maxTop < minTop {
		maxTop = minTop
	}

	p.TopHeight = rand.Intn(maxTop-minTop+1) + minTop
	bottomHeight := 25 - p.TopHeight - gap
	p.BottomY = 25 - bottomHeight
	p.Scored = false
	p.GroundPhase = 0
}

func (p *Pipe) Reset() {
	p.ResetWithGap(getPipeGap(0))
}

func (p *Pipe) Update(amount int) {
	p.PrevX = p.X
	p.X -= amount
	p.GroundPhase = (p.GroundPhase + 1) % 6
}

func (p *Pipe) NeedsReset() bool {
	return p.X < PipeResetX
}

func (p *Pipe) CanScore() bool {
	if p.Scored {
		return false
	}
	return p.PrevX > ScoreX && p.X <= ScoreX
}

func (p *Pipe) MarkScored() {
	p.Scored = true
}

func (p *Pipe) Draw() {
	if p.X+PipeWidth < 0 || p.X > ScreenWidth {
		return
	}

	for y := 1; y <= p.TopHeight; y++ {
		for dx := 1; dx <= 6; dx++ {
			SetCell(p.X+dx, y, ' ', ColorWhite, ColorGreen)
		}
	}
	for dx := 0; dx <= 7; dx++ {
		SetCell(p.X+dx, p.TopHeight+1, ' ', ColorWhite, ColorGreen)
	}

	bottomStart := p.BottomY
	for dx := 0; dx <= 7; dx++ {
		SetCell(p.X+dx, bottomStart, ' ', ColorWhite, ColorGreen)
	}
	for y := bottomStart + 1; y <= 25; y++ {
		for dx := 1; dx <= 6; dx++ {
			SetCell(p.X+dx, y, ' ', ColorWhite, ColorGreen)
		}
	}
}

func (p *Pipe) TopCollisionY() int {
	return p.TopHeight + 1
}

func (p *Pipe) BottomCollisionY() int {
	return p.BottomY
}
