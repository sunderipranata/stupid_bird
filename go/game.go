package main

import (
	"time"
)

type GameState int

const (
	StateMenu GameState = iota
	StatePlaying
	StateGameOver
	StatePaused
	StateShowHighScore
	StateCredits
)

const (
	TickDuration   = 80 * time.Millisecond
	PlayAreaLeft   = 9
	PlayAreaRight  = 68
	PlayAreaTop    = 1
	PlayAreaBottom = 25
)

type Game struct {
	State        GameState
	Bird         *Bird
	Pipes        []*Pipe
	Score        int
	HighScore    int
	Counter      int
	Tick         time.Duration
	MenuSel      int
	IsNewHighScore bool
}

func NewGame() *Game {
	pipe0 := NewPipe()
	pipe1 := NewPipe()
	pipe0.ResetWithGap(getPipeGap(0))
	pipe1.ResetWithGap(getPipeGap(0))

	return &Game{
		State:     StateMenu,
		Bird:      NewBird(),
		Pipes:     []*Pipe{pipe0, pipe1},
		Score:     0,
		HighScore: LoadHighScore(),
		Counter:   0,
		Tick:      TickDuration,
		MenuSel:   1,
	}
}

func (g *Game) Reset() {
	g.Bird.Reset()
	g.Pipes[0].ResetWithGap(getPipeGap(0))
	g.Pipes[1].ResetWithGap(getPipeGap(0))
	g.Score = 0
	g.Counter = 0
	g.IsNewHighScore = false
}

func (g *Game) DrawBackground() {
	FillBackground(ColorWhite, ColorBrightCyan)

	for x := PlayAreaLeft; x <= PlayAreaRight; x += 4 {
		drawTree(x, 0)
	}

	for y := 1; y <= 25; y++ {
		for x := 1; x <= PlayAreaLeft; x++ {
			SetCell(x, y, ' ', ColorWhite, ColorBlack)
		}
		for x := PlayAreaRight + 1; x < ScreenWidth; x++ {
			SetCell(x, y, ' ', ColorWhite, ColorBlack)
		}
	}
}

func drawTree(x, phase int) {
	for dy := 0; dy < 3; dy++ {
		for dx := 0; dx < 4; dx++ {
			if y := 23 + dy; y <= 25 && x+dx < ScreenWidth {
				SetCell(x+dx, y, ' ', ColorWhite, ColorGreen)
			}
		}
	}
}

func (g *Game) DrawMenu() {
	ClearScreen()
	g.DrawBackground()

	for i := 20; i < 40; i += 20 {
		drawMenuBird(i, 15, true)
	}

	title := "STUPID BIRD"
	startX := (ScreenWidth - len(title)*6) / 2
	for i, ch := range title {
		drawLetter(startX+i*6, 5, ch, ColorBrightYellow)
	}

	menuItems := []struct {
		label  string
		selected bool
		x, y   int
	}{
		{"    PLAY    ", g.MenuSel == 1, 17, 5},
		{"  PRACTICE  ", g.MenuSel == 2, 43, 5},
		{"  HIGH SCORE ", g.MenuSel == 3, 32, 16},
		{"   CREDITS   ", g.MenuSel == 4, 32, 17},
		{"  EXIT GAME  ", g.MenuSel == 5, 32, 18},
	}

	for _, item := range menuItems {
		bg := ColorBrightCyan
		if item.selected {
			bg = ColorCyan
		}
		SetString(item.x, item.y, item.label, ColorWhite, bg)
	}

	SetString(48, 25, "Arrow keys to select, Enter to confirm", ColorWhite, ColorBrightCyan)
}

func drawMenuBird(x, y int, wingUp bool) {
	colors := []Color{ColorRed, ColorYellow, ColorWhite, ColorBlack}
	_ = colors

	if wingUp {
		SetCell(x+3, y, ' ', ColorWhite, ColorRed)
		SetCell(x+1, y+1, ' ', ColorWhite, ColorYellow)
		SetCell(x+2, y+1, ' ', ColorWhite, ColorYellow)
		SetCell(x+3, y+1, ' ', ColorWhite, ColorWhite)
		SetCell(x+4, y+1, ' ', ColorWhite, ColorBlack)
		SetCell(x+1, y+2, ' ', ColorWhite, ColorYellow)
		SetCell(x+2, y+2, ' ', ColorWhite, ColorYellow)
		SetCell(x+3, y+2, ' ', ColorWhite, ColorWhite)
		SetCell(x+4, y+2, ' ', ColorWhite, ColorWhite)
		SetCell(x+5, y+2, ' ', ColorWhite, ColorRed)
	} else {
		SetCell(x+3, y, ' ', ColorWhite, ColorRed)
		SetCell(x+1, y+1, ' ', ColorWhite, ColorYellow)
		SetCell(x+2, y+1, ' ', ColorWhite, ColorYellow)
		SetCell(x+3, y+1, ' ', ColorWhite, ColorWhite)
		SetCell(x+4, y+1, ' ', ColorWhite, ColorWhite)
		SetCell(x+1, y+2, ' ', ColorWhite, ColorYellow)
		SetCell(x+2, y+2, ' ', ColorWhite, ColorYellow)
		SetCell(x+3, y+2, ' ', ColorWhite, ColorWhite)
		SetCell(x+4, y+2, ' ', ColorWhite, ColorBlack)
		SetCell(x+5, y+2, ' ', ColorWhite, ColorRed)
	}
	SetCell(x, y+3, ' ', ColorWhite, ColorRed)
	SetCell(x+1, y+3, ' ', ColorWhite, ColorYellow)
	SetCell(x+2, y+3, ' ', ColorWhite, ColorYellow)
	SetCell(x+3, y+3, ' ', ColorWhite, ColorRed)
	SetCell(x+4, y+3, ' ', ColorWhite, ColorYellow)
	SetCell(x+5, y+3, ' ', ColorWhite, ColorRed)
	SetCell(x, y+4, ' ', ColorWhite, ColorRed)
	SetCell(x+1, y+4, ' ', ColorWhite, ColorYellow)
	SetCell(x+2, y+4, ' ', ColorWhite, ColorYellow)
	SetCell(x+3, y+4, ' ', ColorWhite, ColorYellow)
	SetCell(x+4, y+4, ' ', ColorWhite, ColorYellow)
}

var letterData = map[rune][5][5]bool{
	'S': {
		{true, true, true, true, true},
		{true, false, false, false, false},
		{true, true, true, true, true},
		{false, false, false, false, true},
		{true, true, true, true, true},
	},
	'T': {
		{true, true, true, true, true},
		{false, false, true, false, false},
		{false, false, true, false, false},
		{false, false, true, false, false},
		{false, false, true, false, false},
	},
	'U': {
		{true, false, false, false, true},
		{true, false, false, false, true},
		{true, false, false, false, true},
		{true, false, false, false, true},
		{true, true, true, true, true},
	},
	'P': {
		{true, true, true, true, true},
		{true, false, false, false, true},
		{true, true, true, true, true},
		{true, false, false, false, false},
		{true, false, false, false, false},
	},
	'I': {
		{true, true, true, true, true},
		{false, false, true, false, false},
		{false, false, true, false, false},
		{false, false, true, false, false},
		{true, true, true, true, true},
	},
	'D': {
		{true, true, true, true, false},
		{true, false, false, false, true},
		{true, false, false, false, true},
		{true, false, false, false, true},
		{true, true, true, true, false},
	},
	'B': {
		{true, true, true, true, false},
		{true, false, false, false, true},
		{true, true, true, true, false},
		{true, false, false, false, true},
		{true, true, true, true, false},
	},
	'R': {
		{true, true, true, true, false},
		{true, false, false, false, true},
		{true, true, true, true, false},
		{true, false, false, true, false},
		{true, false, false, false, true},
	},
}

func drawLetter(x, y int, ch rune, fg Color) {
	data, ok := letterData[ch]
	if !ok {
		return
	}
	for dy := 0; dy < 5; dy++ {
		for dx := 0; dx < 5; dx++ {
			if data[dy][dx] {
				SetCell(x+dx, y+dy, ' ', ColorWhite, fg)
			}
		}
	}
}

func (g *Game) DrawGame() {
	g.DrawBackground()

	for _, pipe := range g.Pipes {
		pipe.Draw()
	}

	g.Bird.Draw()

	scoreStr := string('0' + byte(g.Score%10))
	if g.Score >= 10 {
		scoreStr = string('0'+byte(g.Score/10)) + scoreStr
	}
	SetString(1, 8, "SCORE:", ColorWhite, ColorBlack)
	SetString(1, 9, scoreStr, ColorWhite, ColorBlack)
}

func (g *Game) DrawGameOver() {
	ClearScreen()
	g.DrawBackground()

	SetString(28, 4, "YOUR SCORE:", ColorWhite, ColorBrightCyan)

	if g.Score < 10 {
		DrawBigNumber(41, 7, g.Score, ColorWhite, ColorBrightCyan)
	} else {
		DrawBigNumber(35, 7, g.Score/10, ColorWhite, ColorBrightCyan)
		DrawBigNumber(41, 7, g.Score%10, ColorWhite, ColorBrightCyan)
	}

	if g.IsNewHighScore {
		SetString(28, 13, "NEW HIGHSCORE!", ColorBrightGreen, ColorBrightCyan)
	}

	SetString(30, 20, "Press SPACE to retry", ColorWhite, ColorBrightCyan)
	SetString(30, 21, "Press ESC for menu", ColorWhite, ColorBrightCyan)
}

func (g *Game) DrawHighScore() {
	ClearScreen()
	g.DrawBackground()

	SetString(28, 4, "HIGH SCORE:", ColorWhite, ColorBrightCyan)
	DrawScore(35, 7, g.HighScore, ColorWhite, ColorBrightCyan)

	SetString(30, 20, "Press any key to continue", ColorWhite, ColorBrightCyan)
}

func (g *Game) DrawCredits() {
	ClearScreen()
	g.DrawBackground()

	credits := []string{
		"STUPID BIRD - Go Version",
		"",
		"Original C++ Version:",
		"Sunderi Pranata (2013)",
		"",
		"Go Rewrite:",
		"Based on original source",
		"",
		"Inspired by Dong Nguyen's Flappy Bird",
	}

	startY := 5
	for i, line := range credits {
		SetString((ScreenWidth-len(line))/2, startY+i, line, ColorWhite, ColorBrightCyan)
	}

	SetString(30, 23, "Press any key to continue", ColorWhite, ColorBrightCyan)
}

func (g *Game) HandleMenuInput(key int) {
	switch key {
	case KeyUp:
		if g.MenuSel == 1 || g.MenuSel == 2 {
			g.MenuSel = 5
		} else if g.MenuSel > 3 {
			g.MenuSel--
		} else {
			g.MenuSel = 5
		}
	case KeyDown:
		if g.MenuSel == 1 || g.MenuSel == 2 {
			g.MenuSel = 3
		} else if g.MenuSel < 5 {
			g.MenuSel++
		} else {
			g.MenuSel = 1
		}
	case KeyRight:
		if g.MenuSel == 1 {
			g.MenuSel = 2
		} else if g.MenuSel == 2 {
			g.MenuSel = 1
		}
	case KeyLeft:
		if g.MenuSel == 2 {
			g.MenuSel = 1
		} else if g.MenuSel == 1 {
			g.MenuSel = 2
		}
	case KeyEnter:
		switch g.MenuSel {
		case 1, 2:
			g.Reset()
			g.State = StatePlaying
		case 3:
			g.HighScore = LoadHighScore()
			g.State = StateShowHighScore
		case 4:
			g.State = StateCredits
		case 5:
			g.State = GameState(-1)
		}
	}
}

func (g *Game) Update(key int) {
	switch g.State {
	case StateMenu:
		if key != 0 {
			g.HandleMenuInput(key)
		}
	case StateGameOver:
		if key == KeySpace {
			g.Reset()
			g.State = StatePlaying
		} else if key == KeyEsc {
			g.State = StateMenu
		}
	case StateShowHighScore, StateCredits:
		if key != 0 {
			g.State = StateMenu
		}
	}
}

func (g *Game) playGame() {
	ClearScreen()
	g.DrawBackground()
	g.Bird.Draw()
	g.Pipes[0].Draw()
	SetString(BirdX-7, BirdStartY+6, "Press SPACE to jump!", ColorWhite, ColorBrightCyan)
	SetString(BirdX-7, BirdStartY+7, "Press ESC for menu", ColorWhite, ColorBrightCyan)
	Refresh()

	for {
		key := readKey()
		if key == KeyEsc {
			g.State = StateMenu
			return
		}
		if key == KeySpace {
			break
		}
		sleep(50)
	}

	g.Bird.Jump()

	for i := 0; i < 3; i++ {
		g.DrawBackground()
		g.Bird.Draw()
		g.Pipes[0].Draw()
		Refresh()

		sleep(100)

		g.Bird.Update()
		g.Pipes[0].Update(1)
		g.Counter++
	}

	for {
		jumpKey := readKey()

		if jumpKey == KeyEsc {
			g.State = StateMenu
			return
		}

		tickMS := getTickMS(g.Score, g.Counter)

		isJumping := (jumpKey == KeySpace)
		steps := 1
		if isJumping {
			g.Bird.Jump()
			steps = 3
		}

		for step := 0; step < steps; step++ {
			g.DrawBackground()
			g.Bird.Draw()
			g.Pipes[0].Draw()
			if g.Counter > 25 {
				g.Pipes[1].Draw()
			}
			g.drawScore()
			Refresh()

			sleep(tickMS)

			if g.Pipes[0].CanScore() {
				g.Score++
				g.Pipes[0].MarkScored()
			}
			if g.Counter > 25 && g.Pipes[1].CanScore() {
				g.Score++
				g.Pipes[1].MarkScored()
			}

			g.Bird.Update()
			g.Pipes[0].Update(1)
			if g.Counter > 25 {
				g.Pipes[1].Update(1)
			}

			if g.Pipes[0].NeedsReset() {
				g.Pipes[0].ResetWithGap(getPipeGap(g.Score))
			}
			if g.Counter > 25 {
				if g.Pipes[1].NeedsReset() {
					g.Pipes[1].ResetWithGap(getPipeGap(g.Score))
				}
			}

			if g.Bird.IsOutOfBounds() {
				g.GameOver()
				return
			}
			if CheckPixelCollision(g.Bird, g.Pipes[0]) {
				g.GameOver()
				return
			}
			if g.Counter > 25 && CheckPixelCollision(g.Bird, g.Pipes[1]) {
				g.GameOver()
				return
			}

			g.Counter++

			if g.Counter == 25 {
				g.Pipes[1].X = PipeStartX
				g.Pipes[1].ResetWithGap(getPipeGap(g.Score))
			}
		}
	}
}

func (g *Game) drawScore() {
	scoreStr := string('0' + byte(g.Score%10))
	if g.Score >= 10 {
		scoreStr = string('0'+byte(g.Score/10)) + scoreStr
	}
	SetString(1, 8, "SCORE:", ColorWhite, ColorBlack)
	SetString(1, 9, scoreStr, ColorWhite, ColorBlack)
}

func (g *Game) GameOver() {
	g.IsNewHighScore, g.HighScore = UpdateHighScoreIfNeeded(g.Score)
	g.State = StateGameOver
}

func (g *Game) Draw() {
	switch g.State {
	case StateMenu:
		g.DrawMenu()
	case StatePlaying:
		g.DrawGame()
	case StateGameOver:
		g.DrawGameOver()
	case StateShowHighScore:
		g.DrawHighScore()
	case StateCredits:
		g.DrawCredits()
	}
}
