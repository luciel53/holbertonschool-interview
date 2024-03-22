#!/usr/bin/python3
"""contains island perimiter"""


def island_perimeter(grid):
    """returns the perimeter of the island described in grid"""
    island_perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:
                for (ver, hor) in ((i - 1, j), (i + 1, j),
                                   (i, j - 1), (i, j + 1)):
                    if ver == -1 or ver >= len(grid) or grid[ver][j] == 0:
                        island_perimeter += 1
                    if hor == -1 or hor >= len(grid[0]) or grid[i][hor] == 0:
                        island_perimeter += 1
    return island_perimeter
