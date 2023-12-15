#!/usr/bin/python3
"""
contains rain function
"""


def rain(walls):
    """
    Given a list of non-negative integers representing the heights of walls,
    as if viewing the cross-section of a relief map,
    calculates how many square units of water will be retained after it rains.
    """
    left_wall_min = []
    right_wall_min = []
    waterhights = []
    minwallhight = 0

    #
    for wall in walls:
        if wall > minwallhight:
            minwallhight = wall
        left_wall_min.append(minwallhight)
    minwallhight = 0

    for wall in walls[::-1]:
        if wall > minwallhight:
            minwallhight = wall
        right_wall_min.append(minwallhight)
    right_wall_min = right_wall_min[::-1]

    for w in range(len(left_wall_min)):
        waterhights.append(min(right_wall_min[w], left_wall_min[w]))

    for w in range(len(waterhights)):
        waterhights[w] = max(0, waterhights[w] - walls[w])

    return(sum(waterhights))
