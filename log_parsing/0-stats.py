#!/usr/bin/python3
"""
    Write a script that reads stdin line by line and computes metrics:

    Input format: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1"
      <status code> <file size> (if the format is not this one, the line
      must be skipped)
    After every 10 lines and/or a keyboard interruption (CTRL + C), print
      these statistics from the beginning:
        Total file size: File size: <total size>
        where <total size> is the sum of all previous <file size>
        (see input format above)
        Number of lines by status code:
            possible status code: 200, 301, 400, 401, 403, 404, 405 and 500
            if a status code doesn’t appear or is not an integer, don’t print
              anything for this status code
            format: <status code>: <number>
            status codes should be printed in ascending order

"""
import sys
import re


# Initialize variables
total_size = 0
status_code_counts = {}
line_count = 0

try:
    for line in sys.stdin:
        line = line.strip()

        # Parse the input line using regular expression
        match = re.match(r'^\d+\.\d+\.\d+\.\d+ - \
                          [.*\] "GET \/projects\/260 HTTP\/1\.1" (\d+) (\d+)$',
                         line)

        if match:
            status_code, file_size = map(int, match.groups())

            # Update total file size
            total_size += file_size

            # Update status code counts
            if status_code in status_code_counts:
                status_code_counts[status_code] += 1
            else:
                status_code_counts[status_code] = 1

            # Increment line count
            line_count += 1

            # Check if we have processed 10 lines
            if line_count % 10 == 0:
                print("Total file size:", total_size)
                for code in sorted(status_code_counts.keys()):
                    print(f"{code}: {status_code_counts[code]}")

except KeyboardInterrupt:
    # Handle keyboard interruption (CTRL + C)
    print("Total file size:", total_size)
    for code in sorted(status_code_counts.keys()):
        print(f"{code}: {status_code_counts[code]}")
