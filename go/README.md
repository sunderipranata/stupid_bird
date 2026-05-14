# Stupid Bird (Go Version)

A terminal-based Flappy Bird clone, rewritten in Go from the original 2013 C++ version.
See `../cpp/` for the original source code.

This is an **AI-assisted rewrite** (opencode.dev) — architecture and code generated through LLM collaboration converting the original DOS-console game to a modern cross-platform Go application.

## Original Gameplay

- **SPACE** - Flap/jump
- **Arrow Keys** - Navigate menu
- **ESC** - Return to menu / Exit
- **ENTER** - Select menu item

## Project Structure

```
go/
├── main.go        # Entry point
├── terminal.go    # ANSI terminal handling, colors, input
├── bird.go        # Bird physics & sprite
├── pipe.go        # Pipe obstacles
├── collision.go   # Collision detection
├── game.go        # Game loop, menu, state
├── score.go       # High score persistence & big digit rendering
├── go.mod         # Go module file
└── README.md      # This file
```

## Requirements

- Go 1.21+

## Dependencies

- `golang.org/x/term` - For terminal raw mode handling (lightweight, standard Go extended library)

## Setup & Build

```bash
# Download dependencies
go mod tidy

# Build
go build -o stupidbird .

# Run
./stupidbird
```

Or run directly:
```bash
go run .
```

## Controls

| Key | Action |
|-----|--------|
| SPACE | Flap / Confirm |
| ↑↓ | Navigate menu up/down |
| ←→ | Switch PLAY/PRACTICE |
| ENTER | Select menu item |
| ESC | Back to menu / Exit |

## Differences from Original C++ Version

### Preserved
- 80x25 terminal-based graphics using colored spaces (matching original "pixel" style)
- Original gravity and jump physics
- Pipe gap and scrolling behavior
- Menu navigation
- Light blue background

### Improvements
- Cross-platform (macOS, Linux, Windows)
- Double-buffered rendering (no flicker)
- ANSI escape codes instead of conio2.h
- Proper handling of arrow keys
- High score saved to highscore.txt

## Architecture

### Design Goals (from user requirements)
- **Idiomatic Go
- **Modular files by responsibility
- **Minimal dependencies** (only golang.org/x/term)
- **Low CPU/memory**
- **No game loop** at ~12 FPS (80ms tick = original timing)

### Key Systems

**Terminal Layer (terminal.go)**
- Double-buffered screen: 80x25 cell buffer
- ANSI background colors
- Arrow key escape sequence parsing
- Raw terminal mode setup/teardown

**Bird Physics (bird.go)**
- Fixed X position (34)
- Jump: -3 Y over 3 sub-ticks
- Gravity: +1 Y per tick
- Two animation states (wing up/down)

**Pipes (pipe.go)**
- Start at X=68
- Scroll left at 1 cell/tick
- Random gap position (2-11 height for top pipe)
- Fixed 11-cell gap
- Second pipe activates after 25 ticks

**Collision (collision.go)**
- Pixel-perfect-ish AABB collision
- Checks bird bounding boxes overlap
- Plus boundary checks (top/bottom of screen)

**Game Loop (game.go)**
- State machine: Menu → Playing → GameOver
- 80ms tick rate
- Input → Update → Draw → Refresh

## Original C++ Issues Fixed

| Original Issue | Fix in Go Version |
|--------------|-------------------|
| `conio2.h` dependency | ANSI escape codes + `golang.org/x/term` |
| `fflush(stdin)` UB | Proper timeout-based input |
| `rand()` without `srand()` | `rand.Seed(time.Now())` |
| Copy-pasted Bird/Bird2 classes | Single Bird type |
| ~100-line hardcoded collision | Simple AABB |
| Windows-only | Cross-platform |
| Binary blobs in git | Source only |

## License

Same as original - educational purposes. Inspired by Dong Nguyen's Flappy Bird.
