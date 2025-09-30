# 🎮 Pong Game

A simple implementation of the classic **Pong** game written in C++ using **SFML**.

---

## 🚀 Features
- Player vs Player (local multiplayer).
- Player vs AI mode.
- Score system.
- Ball bouncing off paddles, walls, floor, and ceiling.
- Basic start menu.

---

## 🛠️ Requirements
- C++17 (or newer) compiler (MSVC / g++ / clang).
- [SFML 3.0+](https://www.sfml-dev.org/download.php).

---
🎮 Controls

Player 1 (left paddle):

W – move up

S – move down

Player 2 (right paddle):

↑ – move up

↓ – move down

Menu: use the mouse to select and click.

Escape: return to menu.

## ⚙️ How to Run

### 🔹 Option 1: Using Visual Studio (Windows)
1. Install **Visual Studio 2022** (with Desktop development with C++).
2. Download **SFML 3.0.2** (Visual C++ 17 (2022) - 64-bit).
3. Unpack SFML somewhere, e.g. `C:\SFML-2.5.1`.
4. In Visual Studio:
   - Right click on your project → **Properties**.
   - Under **C/C++ → General → Additional Include Directories**, add:
     ```
     C:\SFML-3.0.2\include
     ```
   - Under **Linker → General → Additional Library Directories**, add:
     ```
     C:\SFML-3.0.2\lib
     ```
   - Under **Linker → Input → Additional Dependencies**, add:
     ```
     sfml-graphics.lib
     sfml-window.lib
     sfml-system.lib
     sfml-audio.lib
     sfml-network.lib
     ```
   - Make sure you also copy the **DLLs** from `C:\SFML-2.5.1\bin` into your project’s output folder (next to the `.exe`).
5. Build and run!

---

### 🔹 Option 2: Using CMake (Linux / macOS / Windows)
1. Clone the repository:
   ```
   bash
   git clone git@github.com:your-username/pong-game.git
   cd pong-game
2. Build the project:
   ```
   mkdir build && cd build 
   cmake ..
   make
3.Run the game:
   ```
   ./pong
   ```
🕹️ Gameplay

![PONG-GAME](https://github.com/user-attachments/assets/5eab9918-1e50-4f5e-a868-52e579ef1df3)

✨ Author

Created by KubaXQ for educational purposes.
