package main

import (
	"fmt"
	"os"
	"time"
)

var inputBuffer = make(chan int, 100)

func init() {
	go readInput()
}

func readInput() {
	buf := make([]byte, 8)
	for {
		n, err := os.Stdin.Read(buf)
		if err != nil || n == 0 {
			continue
		}
		if buf[0] == 27 {
			if n >= 3 && buf[1] == '[' {
				switch buf[2] {
				case 'A':
					inputBuffer <- KeyUp
				case 'B':
					inputBuffer <- KeyDown
				case 'C':
					inputBuffer <- KeyRight
				case 'D':
					inputBuffer <- KeyLeft
				}
				continue
			}
			inputBuffer <- KeyEsc
			continue
		}
		inputBuffer <- int(buf[0])
	}
}

func readKey() int {
	select {
	case key := <-inputBuffer:
		return key
	default:
		return 0
	}
}

func readKeyBlocking() int {
	for {
		key := <-inputBuffer
		if key != 0 {
			return key
		}
	}
}

func sleep(ms int) {
	time.Sleep(time.Duration(ms) * time.Millisecond)
}

func main() {
	defer func() {
		RestoreTerminal()
		if r := recover(); r != nil {
			fmt.Printf("Error: %v\n", r)
			os.Exit(1)
		}
	}()

	err := InitTerminal()
	if err != nil {
		fmt.Printf("Failed to initialize terminal: %v\n", err)
		os.Exit(1)
	}

	game := NewGame()

	for {
		switch game.State {
		case StateMenu, StateShowHighScore, StateCredits:
			game.Draw()
			Refresh()
			key := readKeyBlocking()
			game.Update(key)
		case StatePlaying:
			game.playGame()
		case StateGameOver:
			game.Draw()
			Refresh()
			key := readKeyBlocking()
			game.Update(key)
		case GameState(-1):
			RestoreTerminal()
			fmt.Println("Thanks for playing!")
			return
		}
	}
}
