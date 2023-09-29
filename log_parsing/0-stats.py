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

file_size = 0


def print_metric():
    """Print of the log."""
    print("File size: {}".format(file_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code]:
            print("{}: {}".format(code, status_codes[code]))


if __name__ == "__main__":
    count = 0
    try:
        for line in sys.stdin:
            try:
                parts = line.split()
                file_size += int(parts[-1])
                if parts[-2] in status_codes:
                    status_codes[parts[-2]] += 1
            except Exception:
                pass
            if count % 10 == 0:
                print_metric()
                count = -1
            count += 1
    except KeyboardInterrupt:
        print_metric()
        raise
    print_metric()
