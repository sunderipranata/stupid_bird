package main

const (
	BirdX         = 34
	BirdStartY    = 10
	BirdWidth     = 6
	BirdHeight    = 5
	JumpStrength  = 3
	Gravity       = 1
	TopBound      = 2
	BottomBound   = 20
)

type Bird struct {
	Y         int
	WingUp    bool
	JumpSteps int
}

func NewBird() *Bird {
	return &Bird{
		Y:        BirdStartY,
		WingUp:   true,
	}
}

func (b *Bird) Reset() {
	b.Y = BirdStartY
	b.WingUp = true
	b.JumpSteps = 0
}

func (b *Bird) Jump() {
	b.JumpSteps = JumpStrength
	b.WingUp = true
}

func (b *Bird) Update() {
	if b.JumpSteps > 0 {
		b.Y -= 1
		b.JumpSteps--
		if b.JumpSteps == 0 {
			b.WingUp = false
		}
	} else {
		b.Y += Gravity
		b.WingUp = false
	}
}

func (b *Bird) IsOutOfBounds() bool {
	return b.Y > BottomBound || b.Y < TopBound
}

func (b *Bird) Draw() {
	if b.WingUp {
		b.drawWingUp()
	} else {
		b.drawWingDown()
	}
}

func (b *Bird) drawWingUp() {
	x := BirdX
	y := b.Y

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

func (b *Bird) drawWingDown() {
	x := BirdX
	y := b.Y

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
