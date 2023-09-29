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


# crate a dictionary to store the status
status_dict = {'200': 0,
               '301': 0,
               '400': 0,
               '401': 0,
               '403': 0,
               '404': 0,
               '405': 0,
               '500': 0}

total_size = 0
count = 0

try:
    for line in sys.stdin:
        # split the line at each word
        words_list = line.split(" ")

        if len(words_list) > 4:
            file_size = int(words_list[-1])
            status_code = words_list[-2]

            # check status code in the dictionary and increment it
            if status_code in status_dict.keys():
                status_dict[status_code] += 1

            #  total size
            total_size += file_size

            # add the line to the count
            count += 1

        if count == 10:
            # reset
            count = 0
            print('File size: {}'.format(total_size))

            # print out status code counts, sorted by status code
            for key, value in sorted(status_dict.items()):
                if value != 0:
                    print('{}: {}'.format(key, value))

except Exception as err:
    pass

finally:
    # total size
    print('File size: {}'.format(total_size))
    for key, value in sorted(status_dict.items()):
        if value != 0:
            print('{}: {}'.format(key, value))
