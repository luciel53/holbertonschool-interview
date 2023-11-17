#!/usr/bin/python3
"""
    N queens puzzle is the challenge of placing N non-attacking queens
    on an N×N chessboard. Write a program that solves the N queens problem.

    Usage: nqueens N
        If the user called the program with the wrong number of arguments,
        print Usage: nqueens N, followed by a new line, and exit with the
        status 1
    where N must be an integer greater or equal to 4
        If N is not an integer, print N must be a number, followed by a new
        line, and exit with the status 1
        If N is smaller than 4, print N must be at least 4, followed by a new
        line, and exit with the status 1
    The program should print every possible solution to the problem
        One solution per line
        Format: see example
        You don’t have to print the solutions in a specific order
    You are only allowed to import the sys module
"""
import sys


def is_safe_position(queen, queens_list):
    """
    Function that returns True if no queen in queens_list is on the same
    diagonal as queen, False otherwise.
    """
    for q in queens_list:
        if (
            queen[0] == q[0] or
            queen[1] == q[1] or
            abs(queen[0] - q[0]) == abs(queen[1] - q[1])
        ):
            return False
    return True


def nqueens_N_helper(n, queens_left, queens_list, solutions, i):
    if queens_left == 0:
        solutions.append(sorted(queens_list))
        return solutions

    for j in range(n):
        if is_safe_position([i, j], queens_list):
            solutions = nqueens_N_helper(n, queens_left - 1, queens_list +
                                         [[i, j]], solutions, i + 1)

    return solutions


def nqueens_N(n):
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = nqueens_N_helper(n, n, [], [], 0)
    if solutions == []:
        print("No Solution")
    else:
        for solution in solutions:
            print(solution)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        parametre_entre = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    nqueens_N(parametre_entre)
