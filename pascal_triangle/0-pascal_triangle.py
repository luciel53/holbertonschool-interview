#!/usr/bin/python3
"""
    create a function def pascal_triangle(n): that returns a list of lists
    of integers representing the Pascal’s triangle of n
"""


def pascal_triangle(n):
    """ triangle pascal function """
    if n <= 0:
        return []

    triangle = []
    for i in range(n):
        row = [1] * (i + 1)
        if i >= 2:
            for j in range(1, i):
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j]
        triangle.append(row)

    return triangle
