package main

func CheckCollision(bird *Bird, pipes []*Pipe) bool {
	if bird.Y > BottomBound {
		return true
	}
	if bird.Y < TopBound-1 {
		return true
	}

	birdLeft := BirdX
	birdRight := BirdX + BirdWidth - 1
	birdTop := bird.Y
	birdBottom := bird.Y + BirdHeight - 1

	for _, pipe := range pipes {
		if pipe.X > ScreenWidth || pipe.X+PipeWidth < 0 {
			continue
		}

		pipeLeft := pipe.X
		pipeRight := pipe.X + PipeWidth - 1

		if birdRight < pipeLeft || birdLeft > pipeRight {
			continue
		}

		gapTop := pipe.TopCollisionY() + 1
		gapBottom := pipe.BottomCollisionY() - 1

		if birdTop < gapTop || birdBottom > gapBottom {
			return true
		}
	}

	return false
}

func CheckPixelCollision(bird *Bird, pipe *Pipe) bool {
	if bird.Y > BottomBound || bird.Y < TopBound-1 {
		return true
	}

	if pipe.X > BirdX+5 || pipe.X+PipeWidth-1 < BirdX {
		return false
	}

	birdPoints := []struct{ dx, dy int }{
		{3, 0},
		{1, 1}, {2, 1}, {3, 1}, {4, 1},
		{1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2},
		{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3},
		{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4},
	}

	gapTop := pipe.TopCollisionY()
	gapBottom := pipe.BottomCollisionY()

	for _, pt := range birdPoints {
		bx := BirdX + pt.dx
		by := bird.Y + pt.dy

		if bx >= pipe.X && bx <= pipe.X+PipeWidth-1 {
			if by <= gapTop || by >= gapBottom {
				return true
			}
		}
	}

	return false
}
