package main

import (
	"bytes"
	"fmt"
	"os"
	"time"

	"golang.org/x/term"
)

const (
	ScreenWidth  = 80
	ScreenHeight = 25
)

type Color int

const (
	ColorBlack Color = iota
	ColorRed
	ColorGreen
	ColorYellow
	ColorBlue
	ColorMagenta
	ColorCyan
	ColorWhite
	ColorBrightBlack
	ColorBrightRed
	ColorBrightGreen
	ColorBrightYellow
	ColorBrightBlue
	ColorBrightMagenta
	ColorBrightCyan
	ColorBrightWhite
)

const (
	KeySpace  = 32
	KeyEsc    = 27
	KeyEnter  = 13
	KeyUp     = 256 + iota
	KeyDown
	KeyRight
	KeyLeft
)

var (
	oldState *term.State
	screen   = make([][]byte, ScreenHeight)
	colors   = make([][]Color, ScreenHeight)
)

func init() {
	for y := range screen {
		screen[y] = make([]byte, ScreenWidth)
		colors[y] = make([]Color, ScreenWidth)
		for x := range screen[y] {
			screen[y][x] = ' '
			colors[y][x] = ColorBrightCyan
		}
	}
}

func InitTerminal() error {
	var err error
	oldState, err = term.MakeRaw(int(os.Stdin.Fd()))
	if err != nil {
		return err
	}
	fmt.Print("\x1b[?25l")
	fmt.Print("\x1b[?1049h")
	ClearScreen()
	return nil
}

func RestoreTerminal() {
	if oldState != nil {
		term.Restore(int(os.Stdin.Fd()), oldState)
	}
	fmt.Print("\x1b[?25h")
	fmt.Print("\x1b[?1049l")
}

func ClearScreen() {
	for y := range screen {
		for x := range screen[y] {
			screen[y][x] = ' '
			colors[y][x] = ColorBrightCyan
		}
	}
}

func FillBackground(fg, bg Color) {
	for y := range screen {
		for x := range screen[y] {
			screen[y][x] = ' '
			colors[y][x] = bg
		}
	}
}

func HideCursor() {
	fmt.Print("\x1b[?25l")
}

func ShowCursor() {
	fmt.Print("\x1b[?25h")
}

func SetCell(x, y int, ch byte, fg, bg Color) {
	if y < 1 || y > ScreenHeight || x < 1 || x > ScreenWidth {
		return
	}
	screen[y-1][x-1] = ch
	colors[y-1][x-1] = bg
}

func SetString(x, y int, s string, fg, bg Color) {
	for i, ch := range s {
		SetCell(x+i, y, byte(ch), fg, bg)
	}
}

func Refresh() {
	var buf bytes.Buffer

	buf.WriteString("\x1b[H")

	currentBg := Color(-1)

	for y := 0; y < ScreenHeight; y++ {
		lineStart := true
		for x := 0; x < ScreenWidth; x++ {
			bg := colors[y][x]
			ch := screen[y][x]

			if lineStart {
				buf.WriteString(fmt.Sprintf("\x1b[%d;%dH", y+1, x+1))
				lineStart = false
			}

			if bg != currentBg {
				buf.WriteString(ansiBg(bg))
				currentBg = bg
			}

			buf.WriteByte(ch)
		}
		if y < ScreenHeight-1 {
			buf.WriteString("\r\n")
		}
	}

	buf.WriteString("\x1b[0m")
	buf.WriteString(fmt.Sprintf("\x1b[%d;%dH", ScreenHeight, ScreenWidth))

	os.Stdout.Write(buf.Bytes())
}

func ansiBg(c Color) string {
	switch c {
	case ColorBlack:
		return "\x1b[40m"
	case ColorRed:
		return "\x1b[41m"
	case ColorGreen:
		return "\x1b[42m"
	case ColorYellow:
		return "\x1b[43m"
	case ColorBlue:
		return "\x1b[44m"
	case ColorMagenta:
		return "\x1b[45m"
	case ColorCyan:
		return "\x1b[46m"
	case ColorWhite:
		return "\x1b[47m"
	case ColorBrightBlack:
		return "\x1b[100m"
	case ColorBrightRed:
		return "\x1b[101m"
	case ColorBrightGreen:
		return "\x1b[102m"
	case ColorBrightYellow:
		return "\x1b[103m"
	case ColorBrightBlue:
		return "\x1b[104m"
	case ColorBrightMagenta:
		return "\x1b[105m"
	case ColorBrightCyan:
		return "\x1b[106m"
	case ColorBrightWhite:
		return "\x1b[107m"
	default:
		return "\x1b[49m"
	}
}

func ReadKey() (int, error) {
	buf := make([]byte, 8)
	os.Stdin.SetReadDeadline(time.Now().Add(50 * time.Millisecond))
	n, err := os.Stdin.Read(buf)
	os.Stdin.SetReadDeadline(time.Time{})

	if err != nil {
		if os.IsTimeout(err) {
			return 0, nil
		}
		return 0, err
	}
	if n == 0 {
		return 0, nil
	}

	if buf[0] == 27 {
		if n >= 3 && buf[1] == '[' {
			switch buf[2] {
			case 'A':
				return KeyUp, nil
			case 'B':
				return KeyDown, nil
			case 'C':
				return KeyRight, nil
			case 'D':
				return KeyLeft, nil
			}
		}
		if n == 1 {
			return KeyEsc, nil
		}
	}

	return int(buf[0]), nil
}
