#!/usr/bin/python3
"""
    Write a script that reads stdin line by line and computes metrics:

    Input format: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1"
    <status code> <file size> (if the format is not this one, the line must
    be skipped)
    After every 10 lines and/or a keyboard interruption (CTRL + C), print
    these statistics from the beginning:
        Total file size: File size: <total size>
        where <total size> is the sum of all previous <file size> (see
        input format above)
        Number of lines by status code:
            possible status code: 200, 301, 400, 401, 403, 404, 405 and 500
            if a status code doesn’t appear or is not an integer, don’t print
            anything for this status code
            format: <status code>: <number>
            status codes should be printed in ascending order
"""


import sys

# Define dictionary to store status codes and initialize their counts to zero
status_codes = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}

# Initialize a variable to store total file size
file_size = 0


def print_metric():
    """ Prints log metrics """
    print("File size: {}".format(file_size))
    # Iterate through status codes and print their counts if > zero.
    for code in sorted(status_codes.keys()):
        if status_codes[code]:
            print(f"{code}: {status_codes[code]}")


if __name__ == "__main__":

    count = 0
    try:
        # Iterate through each line of input from the standard input
        for line in sys.stdin:
            try:
                # Split the line into parts based on whitespace.
                parts = line.split()
                # Add the last part to the total file size.
                file_size += int(parts[-1])
                # If the second-to-last part is valid status code, increment
                if parts[-2] in status_codes:
                    status_codes[parts[-2]] += 1
            except Exception:
                pass

            # Check if the count is a multiple of 10, and print log metrics
            if count % 10 == 0:
                print_metric()
                # Reset count to -1 to avoid double counting on next iteration
                count = -1
            # Increment the count for each processed line
            count += 1
    except KeyboardInterrupt:
        # If a keyboard interrupt received, print log metrics, raise exception
        print_metric()
        raise
    # Print the log metrics at the end of processing
    print_metric()
