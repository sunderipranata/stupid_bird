package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const ScoreFile = "highscore.txt"

func LoadHighScore() int {
	file, err := os.Open(ScoreFile)
	if err != nil {
		return 0
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	if scanner.Scan() {
		score, err := strconv.Atoi(scanner.Text())
		if err == nil {
			return score
		}
	}
	return 0
}

func SaveHighScore(score int) error {
	file, err := os.Create(ScoreFile)
	if err != nil {
		return err
	}
	defer file.Close()

	_, err = fmt.Fprintf(file, "%d", score)
	return err
}

func UpdateHighScoreIfNeeded(currentScore int) (bool, int) {
	high := LoadHighScore()
	if currentScore > high {
		SaveHighScore(currentScore)
		return true, currentScore
	}
	return false, high
}

func DrawBigNumber(x, y, num int, fg, bg Color) {
	if num < 0 || num > 9 {
		return
	}

	digits := [][5][5]bool{
		{
			{true, true, true, true, true},
			{true, false, false, false, true},
			{true, false, false, false, true},
			{true, false, false, false, true},
			{true, true, true, true, true},
		},
		{
			{false, false, false, false, true},
			{false, false, false, false, true},
			{false, false, false, false, true},
			{false, false, false, false, true},
			{false, false, false, false, true},
		},
		{
			{true, true, true, true, true},
			{false, false, false, false, true},
			{true, true, true, true, true},
			{true, false, false, false, false},
			{true, true, true, true, true},
		},
		{
			{true, true, true, true, true},
			{false, false, false, false, true},
			{true, true, true, true, true},
			{false, false, false, false, true},
			{true, true, true, true, true},
		},
		{
			{true, false, false, false, true},
			{true, false, false, false, true},
			{true, true, true, true, true},
			{false, false, false, false, true},
			{false, false, false, false, true},
		},
		{
			{true, true, true, true, true},
			{true, false, false, false, false},
			{true, true, true, true, true},
			{false, false, false, false, true},
			{true, true, true, true, true},
		},
		{
			{true, true, true, true, true},
			{true, false, false, false, false},
			{true, true, true, true, true},
			{true, false, false, false, true},
			{true, true, true, true, true},
		},
		{
			{true, true, true, true, true},
			{false, false, false, true, false},
			{false, false, true, false, false},
			{false, false, true, false, false},
			{false, false, true, false, false},
		},
		{
			{true, true, true, true, true},
			{true, false, false, false, true},
			{true, true, true, true, true},
			{true, false, false, false, true},
			{true, true, true, true, true},
		},
		{
			{true, true, true, true, true},
			{true, false, false, false, true},
			{true, true, true, true, true},
			{false, false, false, false, true},
			{true, true, true, true, true},
		},
	}

	digit := digits[num]
	for dy := 0; dy < 5; dy++ {
		for dx := 0; dx < 5; dx++ {
			if digit[dy][dx] {
				SetCell(x+dx, y+dy, ' ', fg, ColorWhite)
			} else {
				SetCell(x+dx, y+dy, ' ', fg, bg)
			}
		}
	}
}

func DrawScore(x, y, score int, fg, bg Color) {
	if score < 10 {
		DrawBigNumber(x, y, score, fg, bg)
	} else {
		tens := score / 10
		ones := score % 10
		DrawBigNumber(x, y, tens, fg, bg)
		DrawBigNumber(x+6, y, ones, fg, bg)
	}
}
