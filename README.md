# so_long 🎮

A 2D game project built with C and MiniLibX as part of the 42 curriculum. Navigate through mazes, collect items, and find your way to the exit!

## 📋 Table of Contents
- [About](#about)
- [Game Rules](#game-rules)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Map Format](#map-format)
- [Controls](#controls)
- [Project Structure](#project-structure)

## 🎯 About

so_long is a simple 2D game where the player must collect all collectibles (keys) on the map and then reach the exit. The game is built using the MiniLibX graphics library and demonstrates fundamental game development concepts including:
- Map parsing and validation
- Sprite rendering
- Player movement and collision detection
- Event handling
- Memory management

## 🎮 Game Rules

1. The player starts at position 'P' on the map
2. Collect all items marked with 'C' (collectibles)
3. Once all collectibles are gathered, the exit 'E' becomes accessible
4. Reach the exit to win the game
5. Movement count is displayed in the terminal
6. The game can be exited at any time using ESC or closing the window

## 🔧 Requirements

- GCC compiler
- Make
- MiniLibX library
- X11 and Xext libraries (for Linux)
- Linux operating system

## 📦 Installation

1. Clone the repository:
```bash
git clone https://github.com/Guiandrade10/so_long.git
cd so_long
```

2. Install MiniLibX (if not already installed):
```bash
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux
make
cd ..
```

3. Compile the project:
```bash
make
```

This will:
- Compile the Libft library
- Compile the MiniLibX library
- Compile all source files
- Link everything into the `so_long` executable

## 🚀 Usage

Run the game with a map file:
```bash
./so_long maps/map_0.ber
```

### Available Maps
- `maps/map_0.ber` - Small beginner map
- `maps/map1.ber` - Medium difficulty
- `maps/map2.ber` - Larger map with more complexity

### Memory Leak Check
To check for memory leaks using Valgrind:
```bash
make val
```

## 🗺️ Map Format

Maps must be in `.ber` format with the following rules:

### Valid Characters
- `1` - Wall
- `0` - Empty space
- `C` - Collectible item
- `E` - Exit
- `P` - Player starting position

### Map Requirements
- Map must be rectangular (all rows same length)
- Map must be surrounded by walls (`1`)
- Must contain exactly 1 exit (`E`)
- Must contain exactly 1 starting position (`P`)
- Must contain at least 1 collectible (`C`)
- Must have a valid path from player to all collectibles and to the exit

### Example Map
```
111111111
1P0000001
1000C0001
100CEC001
1000C0001
111111111
```

## 🎮 Controls

| Key | Action |
|-----|--------|
| `W` | Move Up |
| `A` | Move Left |
| `S` | Move Down |
| `D` | Move Right |
| `ESC` | Exit game |

## 📁 Project Structure

```
so_long/
├── Makefile              # Build configuration
├── README.md            # This file
├── include/
│   └── so_long.h        # Header file with structures and prototypes
├── src/
│   ├── so_long.c        # Main entry point
│   ├── validate_map.c   # Map validation logic
│   ├── load_map.c       # Map loading and parsing
│   ├── load_textures.c  # Texture/sprite loading
│   ├── render.c         # Rendering functions
│   ├── movement.c       # Player movement logic
│   ├── events.c         # Event handling
│   ├── player_exit.c    # Exit/player interaction
│   ├── validate_path.c  # Path validation (flood fill)
│   ├── validate_wall.c  # Wall validation
│   ├── map_errors.c     # Error handling functions
│   ├── ft_free.c        # Memory cleanup
│   └── end_screen.c     # End game screen
├── maps/                # Sample map files
├── textures/            # Game sprites (.xpm files)
└── Libft/              # Custom C library

```

## 🛠️ Makefile Targets

- `make` or `make all` - Compile the project
- `make clean` - Remove object files
- `make fclean` - Remove object files and executable
- `make re` - Recompile everything
- `make val` - Run with Valgrind to check for memory leaks

## 🎨 Features

- ✅ Smooth player movement with directional sprites
- ✅ Collectible tracking
- ✅ Dynamic exit (opens when all collectibles are gathered)
- ✅ Move counter displayed in terminal
- ✅ Map validation with comprehensive error checking
- ✅ Memory leak prevention
- ✅ Support for various map sizes

## 📝 Notes

- The game uses a 60x60 pixel tile size (IMG_PXL = 60)
- Textures are stored in XPM format
- The project follows the 42 Norm coding standards
- All memory is properly freed before program exit

## 🐛 Error Handling

The game includes comprehensive error checking for:
- Invalid map file extensions
- Non-rectangular maps
- Maps not surrounded by walls
- Invalid map characters
- Missing or duplicate player positions
- Missing exit or collectibles
- Invalid paths (unreachable collectibles/exit)
- Empty lines in map files

## 👨‍💻 Author

Created by gude-and as part of the 42 Lisboa curriculum.

## 📄 License

This project is part of the 42 School curriculum.
