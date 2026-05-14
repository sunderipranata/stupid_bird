# Stupid Bird

A Flappy Bird clone available in **two versions**:

| | `cpp/` | `go/` |
|---|---|---|
| **Language** | C++ (original, 2013) | Go (AI-assisted rewrite, 2026) |
| **Platform** | Windows only | Cross-platform |
| **Rendering** | DOS console + conio2.h | ANSI escape codes |
| **Dependencies** | conio2.h, Windows.h | golang.org/x/term |
| **How to run** | Manual compile (see cpp/README.md) | `go run .` |

---

## Quick Start (Go version)

```bash
cd go
go mod tidy
go run .
```

Controls: SPACE to flap, Arrow keys for menu, ESC to go back.

---

## Structure

```
stupid_bird/
├── cpp/           # Original C++ source code (2013)
│   ├── STUPID BIRD.cpp   # Main entry point
│   ├── coba11.cpp        # Play mode classes
│   ├── coba12.cpp        # Practice mode classes
│   └── ...
├── go/            # Go port
│   ├── main.go
│   ├── game.go
│   ├── bird.go
│   ├── pipe.go
│   ├── collision.go
│   ├── terminal.go
│   ├── score.go
│   └── README.md
└── README.md      # This file
```
