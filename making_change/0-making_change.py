#!/usr/bin/python3
"""
Given a pile of coins of different values, determine the fewest number of
coins needed to meet a given amount total.

    Prototype: def makeChange(coins, total)
    Return: fewest number of coins needed to meet total
        If total is 0 or less, return 0
        If total cannot be met by any number of coins you have, return -1
    coins is a list of the values of the coins in your possession
    The value of a coin will always be an integer greater than 0
    You can assume you have an infinite number of each denomination of coin
    in the list
    Your solution’s runtime will be evaluated in this task
"""


def makeChange(coins, total):
    """
    This function determines the fewest number of coins needed to meet a given
    amount.
    """
    # Use dynamic programming for efficient solution
    dp = [float('inf')] * (total + 1)  # Set DP table with infinity values
    # Base case: 0 coins needed for 0 total
    dp[0] = 0
    # Iterate through each coin value
    for coin in coins:
        # Iterate through all possible totals from 0 to target amount
        for i in range(coin, total + 1):
            # Check if current coin value less than or equal to current total
            if coin <= i:
                # Minimum of current minimum &(previous minimum + 1) using coin
                dp[i] = min(dp[i], dp[i - coin] + 1)
    # Return the answer from the DP table for the target amount
    return dp[-1] if dp[-1] != float('inf') else -1
