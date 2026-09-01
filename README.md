# Snake Game

A classic Snake game written in C++ for Turbo C++ (DOS), with the option to
save your game and continue it later.

Built entirely with standard header files — no `graphics.h`, no external
libraries. The board, the snake and the fruit are all drawn with plain
console characters.

School project (2020) demonstrating **Data File Handling (DFH)** in C++.

**Demo:** https://www.youtube.com/watch?v=ooJ1NYvF0m0

## Features

- Start a new game or continue a saved one
- Save game state (snake, fruit, score, direction) to `data.bin` and resume later
- Highscore that persists between sessions
- Menu with instructions, highscore and credits
- Walls wrap around — the snake only dies by hitting itself

## Controls

| Key | Action |
| --- | ------ |
| `w` | Move up |
| `a` | Move left |
| `s` | Move down |
| `d` | Move right |
| `p` | Pause |
| `x` | Exit without saving |

In the pause menu: `p` to resume, `s` to save and exit, `x` to exit without saving.

## Scoring

Each fruit (`X`) eaten is worth 5 points. The snake grows by one segment.

## How to Run

Requires **Turbo C++** (or DOSBox with Turbo C++ installed) — the code uses
`iostream.h`, `conio.h` and `dos.h`, which modern compilers do not support.

1. Open `SNAKE GAME.CPP` in Turbo C++
2. Compile with `Alt + F9`
3. Run with `Ctrl + F9`

Sample screenshots are in `Sample Outputs.pdf`.

## Authors

- Rohitangshu Bose
- Rupankar Podder
