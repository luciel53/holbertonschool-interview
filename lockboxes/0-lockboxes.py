#!/usr/bin/python3
"""
You have n number of locked boxes in front of you. Each box is numbered
sequentially from 0 to n - 1 and each box may contain keys to the other boxes.

Write a method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    """
     Prototype: def canUnlockAll(boxes)
    boxes is a list of lists
    A key with the same number as a box opens that box
    You can assume all keys will be positive integers
        There can be keys that do not have boxes
    The first box boxes[0] is unlocked
    Return True if all boxes can be opened, else return False
    """
    n = len(boxes)
    # define all the elements on False except the first box
    unlocked_box = [False] * n
    unlocked_box[0] = True
    # create a new list of unblocked boxes
    unlocked_list = [0]

    # browse the list of unlocked boxes
    for box in unlocked_list:
        # browse the keys in the major list
        for key in boxes[box]:
            # Check key is in range. if box associated with it is locked, true
            if key < n and not unlocked_box[key]:
                unlocked_box[key] = True
                # add the keys to unlocked list
                unlocked_list.append(key)

    return all(unlocked_box)
