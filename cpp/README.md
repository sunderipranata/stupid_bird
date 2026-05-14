# Stupid Bird — Original C++ Version

A Flappy Bird clone written in pure C++ for Windows console.
Academic project — UMN Computer Engineering, 2013.

## Requirements

- **Compiler**: Borland Turbo C++, DJGPP, or Visual C++ (with conio2.h support)
- **Platform**: Windows only
- **Libraries**: `<conio2.h>`, `<windows.h>` (Win32 API)

## Build

Compile `STUPID BIRD.cpp` with all `.cpp` files in the same directory:

```bash
# Borland C++
bcc32 STUPID BIRD.cpp

# DJGPP (GCC for DOS)
gcc STUPID BIRD.cpp -o stupidbird.exe

# MSVC (with conio2.h shim)
cl STUPID BIRD.cpp
```

Or just run the precompiled `STUPID BIRD.exe`.

## Files

| File | Role |
|------|------|
| STUPID BIRD.cpp | Entry point, menu, main loop |
| coba11.cpp | Play mode (Bird, Obs, Game classes) |
| coba12.cpp | Practice mode (Bird2, Obs2, Game2 — copy-paste) |
| opening.cpp | Opening animation |
| judul.cpp | Title screen rendering |
| design latarbawah.cpp | Background ground/trees |
| deadbirddata.cpp | Game over bird sprite |
| numberdata.cpp | Big digit rendering (0-9) |

## Controls

| Key | Action |
|-----|--------|
| SPACE | Flap / Select |
| Arrow keys | Navigate menu |
| ENTER | Confirm |

## Architecture (original)

All `.cpp` files are `#include`d from `STUPID BIRD.cpp` as a single translation unit.
No proper header/source separation — `.cpp` files act as headers.

## Notes

- Uses DOS-style text-mode graphics (colored spaces)
- Relies on `conio2.h` (non-standard, Borland/DJGPP era)
- Windows-only: `Beep()`, `Sleep()`, `system("cls")` via Win32 API
- Deterministic randomness: `rand()` without `srand()`

## Credit

Ideas & Programmer: Sunderi Pranata  
Illustrator: Ivanka Desyra Susanto  
Sound: Erwin Chua
