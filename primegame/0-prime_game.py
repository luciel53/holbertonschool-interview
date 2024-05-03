#!/usr/bin/python3
"""
    Maria and Ben are playing a game. Given a set of consecutive integers
    starting from 1 up to and including n, they take turns choosing a prime
    number from the set and removing that number and its multiples from the
    set. The player that cannot make a move loses the game.
"""


def isWinner(x, nums):
    """ function that determines who is winner """
    if x < 1:
        return None
    Ben_wins = 0
    for num in nums:
        maria_winning = 1
        numbers = list(range(2, num + 1))
        while numbers != []:
            number = numbers[0]
            if maria_winning:
                maria_winning = 0
            else:
                maria_winning = 1
            for delet in range(number, num + 1, number):
                try:
                    numbers.remove(delet)
                except ValueError:
                    pass
        Ben_wins += maria_winning
        if Ben_wins >= (x/2):
            return "Ben"
    return "Maria"
