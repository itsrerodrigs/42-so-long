
# 🎮 so_long - 42 School

**so_long** is a small 2D game developed in C as part of the 42 School curriculum. It uses **MiniLibX**, a lightweight graphics library, to render a tile-based map with a player, collectibles, walls, enemies, and an exit. The goal is to reach the exit after collecting all items — all while managing memory manually with no leaks. 🧠

## 📋 Features

- 🧱 **Tile-based rendering**: Displays walls, ground, player, collectibles, enemies, and an exit using `.xpm` sprites.
- 🎮 **Player movement**: Real-time keyboard input for navigating the map.
- 🗺️ **Map parsing**: Reads and validates map files (`.ber`) with error handling.
- 🧠 **Memory management**: Full manual control over memory with no leaks (checked with Valgrind).
- ⚙️ Built following **42's Norminette** coding standards.

## 🛠️ Installation

### Prerequisites

Make sure you have:

- 🐧 **Linux** system (MiniLibX is used in its Linux version)
- 🧰 **GCC** or compatible C compiler
- 📦 **make** utility
- 📁 **MiniLibX** and **libft** included in the project (`libs/`)

### Steps to Build

1. **Clone the repository**:
    ```bash
    git clone https://github.com/your-username/so_long.git
    cd so_long
    ```

2. **Compile the project**:
    ```bash
    make
    ```

   This will generate the `so_long` executable.

## 🚀 Usage

To play the game, simply run the executable with a valid map file:

```bash
./so_long maps/map.ber
```

Map files must follow the required format (rectangular, surrounded by walls, containing one player, one exit, and at least one collectible).

## 🎨 Sprites & Assets

All game elements use `.xpm` images stored in the `assets/` folder:

- 👑 Player (Evil Queen)
- 🍎 Collectibles (e.g., apples)
- ✨ Exit (Enchanted Mirror)
- 🌿 Walls (Bushes)
- 🌱 Ground

You can customize these images as long as they remain `64x64` pixels and compatible with MiniLibX.

## 🧹 Cleaning Up

- Remove object files:
    ```bash
    make clean
    ```

- Remove all compiled files and executables:
    ```bash
    make fclean
    ```

- Recompile everything from scratch:
    ```bash
    make re
    ```

## 🛡️ Memory Leak Testing

Use [Valgrind](https://valgrind.org/) to check for memory leaks:

```bash
valgrind ./so_long maps/map.ber
```

Your output should confirm that all allocated memory is freed properly.

---

Made with ❤️ and manual memory management as part of the 42 School core projects.
