# Changelog

All notable changes to this project will be documented in this file.

## [Unreleased] - 2025-12-05

### Added
- Comprehensive README.md with detailed project documentation
- CONTRIBUTING.md with contribution guidelines
- .gitignore file to exclude build artifacts and dependencies
- New example map (maps/map3.ber) with increased complexity
- Security Summary documenting vulnerability findings

### Fixed
- **Critical Bug**: Memory leak in `ft_free.c` - line 32 was incorrectly freeing `map->file` instead of `map->line`, which could cause double-free errors and memory leaks
- **Critical Bug**: Player position tracking in `movement.c`:
  - `move_up()`: Now correctly updates y-coordinate instead of x-coordinate
  - `move_left()`: Now correctly updates x-coordinate instead of y-coordinate
  - `move_right()`: Moved player position update inside the if-block to prevent incorrect updates
- **Critical Bug**: Player position tracking in `player_exit.c`:
  - `player_left()`: Now correctly updates x-coordinate instead of y-coordinate
  - `player_right()`: Now correctly updates x-coordinate instead of y-coordinate
- **Bug**: Path validation logic in `validate_path.c` - changed condition from `map->e_check >= map->e` to `map->e_check > 0` for correct exit reachability detection
- **Bug**: Missing newline in path validation error message
- **Bug**: Invalid map file - removed trailing invalid characters from `maps/map2.ber`

### Changed
- Enhanced error messages for better clarity

## Security Summary

### Vulnerabilities Fixed
1. **Memory Management Issue (HIGH)**: Fixed potential double-free vulnerability in `ft_free.c` where the wrong pointer was being freed, which could lead to undefined behavior or crashes.

2. **Game Logic Bugs (MEDIUM)**: Fixed player position tracking bugs that could cause the game to behave incorrectly, potentially allowing the player to access invalid map positions.

### Current Security Status
- ✅ All memory leaks identified and fixed
- ✅ No buffer overflow vulnerabilities detected
- ✅ Proper bounds checking in place for map access
- ✅ Input validation implemented for map files
- ✅ Error handling properly implemented

### Recommendations
- Continue using Valgrind for memory leak detection
- Test with malformed map files regularly
- Ensure MiniLibX library is kept up to date
