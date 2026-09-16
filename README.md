# Cub3D

A 3D raycasting maze game inspired by classic Wolfenstein 3D, built in C with MiniLibX.

This project parses a custom `.cub` map format, validates the map, loads textures, and renders a first-person view using raycasting. It also includes keyboard movement, rotation, and wall-collision logic.

## Features

- Raycasting-based 3D rendering
- Custom map parser and validation for `.cub` files
- Texture support using `.xpm` files
- Floor and ceiling color parsing
- Player movement and rotation controls
- Wall collision and map integrity checks
- Linux / X11 compatible implementation with MiniLibX

## Project status

This project is a functional maze renderer and game prototype. It follows the standard 42 Cub3D requirements and is designed to parse valid map files, reject invalid configurations, and render the scene in real time.

## Requirements

- Linux environment
- X11 development libraries
- make and a C compiler (`cc`)
- MiniLibX included in the repository

## Build

From the project root:

```bash
make
```

This builds the executable named `cub3D` and compiles the custom library and MiniLibX dependencies defined in the Makefile.

### Cleaning up

```bash
make clean
make fclean
```

## Run

```bash
./cub3D maps/valid/map1.cub
```

You can replace the map path with any valid map file in the `maps/` directory.

## Controls

- `W` : move forward
- `S` : move backward
- `A` : strafe left
- `D` : strafe right
- Left arrow : rotate left
- Right arrow : rotate right
- `ESC` : quit the game

## Map format

A valid `.cub` file must contain:

- 4 texture identifiers:
  - `NO`
  - `SO`
  - `WE`
  - `EA`
- floor color: `F r,g,b`
- ceiling color: `C r,g,b`
- a closed playable map made of walls and empty space
- exactly one starting player position (`N`, `S`, `E`, `W`)

Example:

```text
NO ./assets/north_texture.xpm
SO ./assets/south_texture.xpm
WE ./assets/west_texture.xpm
EA ./assets/east_texture.xpm

F 20,0,0
C 120,100,0

111111111111
100000000001
100110000001
100000000001
100000N00001
111111111111
```

### Map rules

- `1` = wall
- `0` = empty space
- `N`, `S`, `E`, `W` = player starting position
- The map must be surrounded by walls
- There must be no invalid characters
- Textures and colors must be declared before the map

## Project structure

```text
.
├── Makefile
├── README.md
├── assets/
│   └── *.xpm texture files
├── includes/
│   └── project headers
├── libft/
│   └── custom C utility library
├── maps/
│   ├── valid/
│   └── invalid/
├── minilibx-linux/
│   └── MiniLibX dependency
├── src/
│   ├── graphics/
│   ├── parser/
│   ├── singleton/
│   └── main.c
└── vtester.sh
```

## Parser and rendering architecture

The codebase is split into two main concerns:

1. Parsing and validation
   - checks file extension and map format
   - validates texture paths and RGB values
   - verifies the map structure and player position

2. Graphics and gameplay
   - initializes MiniLibX window and image buffers
   - loads textures
   - performs DDA raycasting
   - renders walls, floor, and ceiling
   - handles keyboard events and movement

## Notes

- The project uses a custom `libft` implementation.
- The game is intended to be run in a graphical Linux session with X11 support.
- Invalid maps are rejected early with clear parser errors.
