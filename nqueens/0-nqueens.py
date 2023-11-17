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


def verif(queen, queens_list, n):
    """
    function that returns True if no queen in queens_list is on the same
    diagonale as queen False otherwise
    """
    for q in queens_list:
        if queen[0] == q[0] or queen[1] == q[1]:
            return False

    check = [0, 0]
    check[0] = queen[0]
    check[1] = queen[1]
    for i in range(n):
        check[0] += 1
        check[1] += 1
        for q in queens_list:
            if check == q:
                return False

    check[0] = queen[0]
    check[1] = queen[1]
    for i in range(n):
        check[0] -= 1
        check[1] += 1
        for q in queens_list:
            if check == q:
                return False

    check[0] = queen[0]
    check[1] = queen[1]
    for i in range(n):
        check[0] += 1
        check[1] -= 1
        for q in queens_list:
            if check == q:
                return False

    check[0] = queen[0]
    check[1] = queen[1]
    for i in range(n):
        check[0] -= 1
        check[1] -= 1
        for q in queens_list:
            if check == q:
                return False
    return True


def nqueens_N(n, nbQ, queens_list=[], solutions=[]):
    if nbQ == 0:
        if sorted(queens_list) not in solutions:
            solutions.append(sorted(queens_list))
        return (solutions)
    for i in range(n):
        for j in range(n):
            ql = queens_list.copy()
            if verif([i, j], queens_list, n):
                ql.append([i, j])
                answer = nqueens_N(n, nbQ - 1, ql, solutions)
                if answer != "No Solution":
                    solutions = answer
    if queens_list == []:
        return (solutions)
    return("No Solution")


parametre_entré = int(sys.argv[1])
for n in nqueens_N(parametre_entré, parametre_entré):
    print(n)
