#!/usr/bin/python3
"""
Test  - Rotate 2D Matrix
"""

def rotate_2d_matrix(matrix):
    length = len(matrix)
    new_matrix = []
    for i in range(length):
        new_matrix.append([])
        for j in range(length):
            new_matrix[i].append(0)
    for i in range(length):
        for j in range(length):
            new_matrix[j][length - i - 1] = matrix[i][j]

    for i in range(length):
        matrix[i] = new_matrix[i]

