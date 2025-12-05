# Contributing to so_long

Thank you for your interest in contributing to so_long! This document provides guidelines for contributing to the project.

## Code Style

This project follows the [42 Norm](https://github.com/42School/norminette) coding standards. Please ensure your code complies with:

- Functions must not exceed 25 lines
- Maximum 5 functions per file (with some exceptions)
- No more than 4 parameters per function
- No variable declarations and assignments on the same line
- Proper indentation and formatting

## Before Submitting Changes

1. **Test Your Changes**
   ```bash
   make re
   ./so_long maps/map_0.ber
   ```

2. **Check for Memory Leaks**
   ```bash
   make val
   ```

3. **Verify Map Validation**
   - Test with valid maps
   - Test with invalid maps (wrong extension, invalid walls, no valid path, etc.)

## Adding New Features

When adding new features:

1. Keep changes minimal and focused
2. Update documentation if needed
3. Test thoroughly with different map configurations
4. Ensure memory is properly managed

## Bug Reports

When reporting bugs, please include:

- Description of the issue
- Steps to reproduce
- Expected behavior
- Actual behavior
- Map file used (if applicable)

## Map Creation Guidelines

When creating new map files:

1. Use `.ber` extension
2. Ensure the map is rectangular
3. Surround the map with walls (`1`)
4. Include exactly one player (`P`)
5. Include exactly one exit (`E`)
6. Include at least one collectible (`C`)
7. Ensure there's a valid path from player to all collectibles and to the exit

## Questions?

If you have questions about contributing, feel free to open an issue for discussion.
