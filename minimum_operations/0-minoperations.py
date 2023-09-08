#!/usr/bin/python3
"""
In a text file, there is a single character H. Your text editor can execute
only two operations in this file: Copy All and Paste. Given a number n, write
a method that calculates the fewest number of operations needed to result in
    exactly n H characters in the file.

    Prototype: def minOperations(n)
    Returns an integer
    If n is impossible to achieve, return 0
"""


def minOperations(n):
    """find if n is prime"""
    operations = 0
    prime_number = True

    if n <= 1:
        return 0

    # if n = 2 or 3 so it is prime so n is equal to operation number
    if n == 2 or n == 3:
        operations += n
        return operations

    for i in range(2, n):
        if n % i == 0:
            # not prime
            prime_number = False

    if prime_number is True:
        return n  # if n is prime, operation number is equal to n

    # find prime divisors of n and add them
    for i in range(2, n):
        while n % i == 0:
            n /= i
            operations += i

    return operations
