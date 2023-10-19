#!/usr/bin/python3
"""
Write a method that determines if a given data set represents a valid UTF-8
encoding.

    Prototype: def validUTF8(data)
    Return: True if data is a valid UTF-8 encoding, else return False
    A character in UTF-8 can be 1 to 4 bytes long
    The data set can contain multiple characters
    The data will be represented by a list of integers
    Each integer represents 1 byte of data, therefore you only need to handle
    the 8 least significant bits of each integer
"""


def validUTF8(data):
    # Initialize to store number of bytes
    nb_bytes = 0

    # browse the list of integers (1 int representing 1 byte of data)
    for num in data:
        # Check the 8 last bits. If more than 4  bytes, not valid
        if nb_bytes == 0:
            if num < 128:  # One-byte
                nb_bytes = 0
            elif 192 <= num < 224:  # Two-byte
                nb_bytes = 1
            elif 224 <= num < 240:  # Three-byte
                nb_bytes = 2
            elif 240 <= num < 248:  # Four-byte
                nb_bytes = 3
            else:
                return False  # Invalid
        else:
            # Check if the current byte is part of a multi-byte character
            if 128 <= num < 192:
                nb_bytes -= 1
            else:
                return False

        # Check for the validity of the value in the multi-byte sequence.
        if nb_bytes > 0:
            if not (128 <= num < 192):
                return False

    # if nb_bytes not zero, it's an incomplete character sequence.
    return nb_bytes == 0
