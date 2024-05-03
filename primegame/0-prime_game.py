#!/usr/bin/python3
"""
    Maria and Ben are playing a game. Given a set of consecutive integers
    starting from 1 up to and including n, they take turns choosing a prime
    number from the set and removing that number and its multiples from the
    set. The player that cannot make a move loses the game.
"""


def isWinner(x, nums):
    """ function that determines who is winner """
    def is_prime(num):
        """ prime numbers """
        if num < 2:
            return False
        for i in range(2, int(num ** 0.5) + 1):
            if num % i == 0:
                return False
        return True

    def next_prime(start):
        """ next prime number """
        num = start + 1
        while not is_prime(num):
            num += 1
        return num

    def game_winner(n):
        """ If n is even, Ben will win because Maria starts """
        if n % 2 == 0:
            return "Ben"
        else:
            return "Maria"

    winners = []
    for n in nums:
        if n == 1:
            # If n is 1, Ben wins because there are no prime numbers to choose
            winners.append("Ben")
        else:
            prime_count = 0
            current_prime = 1
            while current_prime <= n:
                prime_count += 1
                current_prime = next_prime(current_prime)
                # If there are no more primes, the other player wins
                if current_prime > n:
                    winners.append(game_winner(prime_count))
                    break

    maria_wins = winners.count("Maria")
    ben_wins = winners.count("Ben")

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
