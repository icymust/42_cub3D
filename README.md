*This project has been created as part of the 42 curriculum by mmustone, abardhan.*

# cub3D

## Description

**cub3D** is a small 3D maze renderer inspired by the early first-person game
Wolfenstein 3D. The goal of the project is to build a dynamic first-person view
of a maze using raycasting and the MiniLibX graphics library.

The program reads a `.cub` scene file, validates its textures, colors, and map,
then renders the scene from the player's point of view. The project covers file
parsing, memory management, event handling, collision detection, texture mapping,
and the mathematics behind a basic raycasting engine.

## Features

- Textured walls with different textures for north, south, east, and west
- Configurable floor and ceiling colors
- First-person movement and camera rotation
- Wall collision detection
- Validation of scene configuration and closed maps
- Clean shutdown and error handling
- Linux and macOS build targets

## Instructions

### Requirements

The project requires a C compiler, `make`, and the libraries needed by MiniLibX.
On Linux, this includes X11, Xext, BSD, and the math library. On macOS, the
OpenGL and AppKit frameworks are used.

### Compilation

On Linux:

```sh
make
```

On macOS:

```sh
make mac
```

Other available Makefile targets are:

```sh
make clean    # remove object files
make fclean   # remove object files and the executable
make re       # rebuild the project from scratch
```

### Execution

Run the program with a valid `.cub` scene file:

```sh
./cub3D maps/lvl1.cub
```

The scene must define four `.xpm` wall textures, floor and ceiling RGB colors,
and a closed map containing exactly one player position.

### Controls

| Key | Action |
| --- | --- |
| `W` / `S` | Move forward / backward |
| `A` / `D` | Strafe left / right |
| Left / Right arrow | Rotate the camera |
| `Esc` | Exit the program |

The window's close button also exits the program cleanly.

## Scene format

A minimal `.cub` file has the following structure:

```text
NO path/to/north_texture.xpm
SO path/to/south_texture.xpm
WE path/to/west_texture.xpm
EA path/to/east_texture.xpm
F 40,40,40
C 120,180,255

11111
10N01
10001
11111
```

Map characters are `0` for walkable space, `1` for a wall, and `N`, `S`, `E`,
or `W` for the player's initial position and orientation. Spaces may be used in
the map layout, but the walkable area must remain completely surrounded by walls.

## Technical overview

For every vertical column of the window, the engine casts a ray from the player
into the map. A DDA traversal finds the first wall hit, after which the engine
calculates its projected height and selects the correct texture and texture
coordinate. This produces the perspective view one screen column at a time.

## Resources

- [42 cub3D subject, version 12.0](docs/cub3d_subject.pdf) — project requirements and scene format
- [Lode's Computer Graphics Tutorial: Raycasting](https://lodev.org/cgtutor/raycasting.html) — raycasting and DDA fundamentals
- [MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx) — window, image, and event APIs
- [Permadi's Ray-Casting Tutorial](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/) — conceptual explanation of raycasting
- [Digital Differential Analyzer](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm)) — background on the grid traversal algorithm

### Use of AI

AI was used as a supporting tool to review parts of the parsing and cleanup
logic, help diagnose memory leaks from validation error paths, clarify edge cases
in the `.cub` format, and assist with drafting this README. The implementation,
technical decisions, testing, and final verification were performed by the
project authors.
